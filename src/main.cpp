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

int main( int argc, char **argv )
{
	
	const int SIZE = 10;
	const int MATCH_LIMIT = 3;

	// Generation inicializer
	Gen current_gen( SIZE );

	// Will populate the generation with random cells 
	current_gen.random_it();
	current_gen.hash(); // generate first hash for the generation


	// hashes vector
	std::vector<std::string> hashes_table;

	while(true){
		// Header
		system("clear");
		std::cout << ">> Generation Age: " << current_gen.age++ << std::endl;

		std::string current_hash = current_gen.hash(); // generate hash for this config

		
		// will return true if the hash is on the hashes_table
		size_t counter = 0;
		bool status_hash = current_gen.check_hash( hashes_table, current_hash, MATCH_LIMIT, counter );

		if( status_hash )
		{
			current_gen.print(' ', '*', ' ');
			std::cout << ">> Configuration is now stable/extint!" << std::endl;
			break;
		}
		else
		{
			// adds current_hash to the hashes table
			hashes_table.push_back( current_hash );
			current_gen.print(' ', '*', ' ');

			// Debug print for the current hash
			std::cout << "~ SHA256: " << current_hash << std::dec;
			std::cout << std::endl;

			current_gen.next();	// This function will generate next gen
			// current_gen.update();	// Will update current gen to next gen
		}

		// A simple timer, so we can interpret results
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}
	std::cout << ">> Simulation finished!" << std::endl;

	return 0;
}
