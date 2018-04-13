#include "canvas.hpp"

void Canvas::create_screen( int x, int y ){
	// record values on the class private members
	this->width = x;
	this->height = y;

	// then, allocate the screen
	this->pixel = new Cell *[height];
	for( int i = 0; i < this->height; i++ ){
		this->pixel[i] = new Cell[this->width];
	}
}

void Canvas::free_screen( void ){
	for(int i = 0; i < height; i++ ){
		delete[] this->pixel[i];
	}
	delete[] this->pixel;
}

void Canvas::print( char separator, char alive_c, char dead_c ){
	for( int i = 0; i < this->height; i++ ){
		for( int j = 0; j < this->width; j++ ){
			if( this->pixel[i][j].is_alive() == true ){
				std::cout << alive_c << separator;
			} else {
				std::cout << dead_c << separator;
			}
		}
		std::cout << std::endl;
	}	
}
