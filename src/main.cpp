#include <iostream>
#include <thread>
#include <chrono>

#include "util.hpp" // utils lib (Cell things)
#include "canvas.hpp" // canvas functions (print, next_gen..)
#include "generation.hpp" // generation functions

int main( int argc, char **argv ) {
	const int SIZE = 50;

	// Generation inicializer
	Gen *current_gen = new Gen;
	current_gen->create( SIZE );
	current_gen->random_it();
	char buf;

	for(int i = 0; i < 100; i++){
		system("clear");
		std::cout << "Generation: " << i << std::endl;
		current_gen->next();
		// current_gen->random_it();
		current_gen->print(' ', '*', ' ');
		// std::cout << std::endl;
		// std::cin >> buf;
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
	}

	current_gen->free();

	return 0;
}
