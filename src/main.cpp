/* Author: Felipe Ramos */

#include <iostream>			// std:: related functions
#include <fstream>			// input/output files
#include <thread> 			// Using sleep thread function
#include <chrono> 			// Using time functions
#include <vector>			// used to store sha256 strings

#include "sha256.hpp"		// To generate hashes of a given string
#include "cell.hpp" 		// Cells classes implementations
#include "canvas.hpp" 		// Everything related to screen, canvas
#include "generation.hpp" 	// Everything related to generating new patterns
#include "io.hpp"			// input operations

#define argc_argv_debug 0	// on = argc & argv debug state (simulator off)
#define FPS 1 				// Frames per second of the simulator

int main( int argc, char **argv )
{
	if( argc != 2 )
	{
		std::cout << "\n\tInvalid format!\n";
		std::cout << "\tUSE: ./conway <input_cfg_file>\n\n";
		return 1;
	}

	std::ifstream config_file(argv[1]);		// create file stream

	if(!config_file)
	{
		std::cout << "\n\tPlease, inform a valid file.\n\n";
		return 1;
	}

	Gen *current_gen = parse(config_file);	// parse file config's

	const int MATCH_LIMIT = 1; 		// This defines with how many equals SHA256
									// the program will stop

	// Generation inicializer, use if you want to generate pseudo random cells
	// To use, uncomment next 2 lines and comment the parse() line. (up)
	// Gen *current_gen = new Gen( 30 );
	// current_gen->random_it(); 	// It will populate with random cells

	current_gen->hash(); 			// generates the first hash

	// All canvas hashes will be stored here
	std::vector<std::string> hashes_table;

	while(true && !argc_argv_debug ){
		// Header
		system("clear");
		std::cout << ">> Generation Age: " << current_gen->age++ << std::endl;
		std::string current_hash = current_gen->hash(); // generate hash for this config

		
		size_t counter = 0;
		bool status_hash;
		// A hasher function that returns if a hash is present on the table
		status_hash = current_gen->check_hash( hashes_table,
											   current_hash,
											   MATCH_LIMIT,
											   counter );

		if( status_hash ) 	// then the hash is repeated
		{
			current_gen->print(' ', '*', '.'); 	// print the atual generation

			// it will count how many alive cells
			size_t alive_count = current_gen->count_alives();
			if( alive_count > 0 )
			{
				std::cout << ">> Configuration is now stable!" << std::endl;
			}
			else
			{
				std::cout << ">> Configuration is now extint!" << std::endl;
			}
			break;
		}
		else
		{
			// Adds current_hash to the hashes table
			hashes_table.push_back( current_hash );

			// print the actual canvas
			current_gen->print(' ', '*', ' ');

			// Debug print for the current hash
			std::cout << "\nSHA256: " << current_hash << std::dec;
			std::cout << std::endl;

			// will generate next gen
			current_gen->next();
		}

		// A simple timer, so we can interpret results
		// FPS is defined via #define, on the begin of the file
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000/FPS ) );
	}

	// A cool looking print :D
	std::cout << "\n>> Simulation finished!" << std::endl;

	// Destroy everything
	delete current_gen;

	return 0;

	// It was a pleasure, gentlemen
}
