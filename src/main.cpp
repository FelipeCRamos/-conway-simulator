#include <iostream>
#include "util.hpp" // utils lib (Cell things)
#include "canvas.hpp" // canvas functions (print, next_gen..)
#include "generation.hpp" // generation functions

int main( int argc, char **argv ) {
	const int SIZE = 40;

	// Generation inicializer
	Gen *current_gen = new Gen;
	current_gen->create( SIZE );

	for(int i = 0; i < 3; i++){
		std::cout << "Generation: " << i << std::endl;
		current_gen->next();
		current_gen->random_it();
		current_gen->print();
		std::cout << std::endl;
	}

	current_gen->free();

	return 0;
}
