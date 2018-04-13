#include "canvas.hpp"

void Canvas::create_screen( int x, int y ){
	// record values on the class private members
	width = x;
	height = y;

	// then, allocate the screen
	screen = new Cell *[height];
	for( int i = 0; i < height; i++ ){
		screen[i] = new Cell[width];
	}
}

void Canvas::free_screen( void ){
	for(int i = 0; i < height; i++ ){
		delete[] screen[i];
	}
	delete[] screen;
}

void Canvas::print( char separator, char alive_c, char dead_c ){
	for( int i = 0; i < height; i++ ){
		for( int j = 0; j < width; j++ ){
			if( screen[i][j].is_alive() == true ){
				std::cout << alive_c << separator;
			} else {
				std::cout << dead_c << separator;
			}
		}
		std::cout << std::endl;
	}	
}
