#include <iostream>
#include <thread> // Using sleep thread function
#include <chrono> // Using time functions

#include "util.hpp" // Cells classes implementations
#include "canvas.hpp" // Everything related to screen, canvas
#include "generation.hpp" // Everything related to generating new patterns

int main( int argc, char **argv ) {
	// The size of the matrix that will be created
	const int SIZE = 100;

	// Generation inicializer
	Gen *current_gen = new Gen;
	current_gen->create( SIZE );
	current_gen->random_it();

	char buf; // A buffer variable

	for(int i = 0; i < 400; i++){
		system("clear");
		std::cout << "Generation: " << i << std::endl;
		current_gen->next();
		current_gen->update();
		current_gen->print(' ', '*', ' ');
		std::this_thread::sleep_for( std::chrono::milliseconds( 150 ) );
	}

	current_gen->free();

	return 0;
}
