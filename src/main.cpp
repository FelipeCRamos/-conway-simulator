/* Author: Felipe Ramos */
#include <iostream>
#include <fstream>
#include <thread> 			// Using sleep thread function
#include <chrono> 			// Using time functions

#include "cell.hpp" 		// Cells classes implementations
#include "canvas.hpp" 		// Everything related to screen, canvas
#include "generation.hpp" 	// Everything related to generating new patterns
#include "io.hpp" 			// All the Input/Output functions (.dat reading)

int main( int argc, char **argv ) {

	// TODO: implement argv size
	const int SIZE = 10;

	// Generation inicializer
	Gen *current_gen = new Gen( SIZE );

	// Will populate the generation with random cells 
	current_gen->random_it();

	// Control variables
	bool stable = false; 	// If the generation is stable, stable = true;
	int stable_count = 0;	// How many stable generations has been
	int i = 0;				// Simple generation counter


	while(true){
		// Header
		system("clear");
		std::cout << "Generation: " << i++ << std::endl;

		// will return true if stability is detected
		stable = current_gen->next();	// This function will generate next gen

		if( stable_count > 0 and stable == false )
			// if the generation x was stable and generation x+1 wasn't, then
			stable_count = 0;

		current_gen->update();	// Will update current gen to next gen

		// This will print current generation based on:
		// separator, alive_cells, dead_cells
		current_gen->print(' ', '*', ' ');

		if(stable == true)
			stable_count++;

		if(stable_count > 1)
			// if in generation x and generation x+1 were stable, then break
			break;

		// A simple timer, so we can interpret results
		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}
	std::cout << "Simulation complete!" << std::endl;

	// free of the allocated variables
	delete current_gen;

	return 0;
}
