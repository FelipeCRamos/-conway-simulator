#include "canvas.hpp"

Canvas::Canvas( int x, int y ){
	this->width = x;
	this->height = y;

	// then, we allocate the canvas
	this->pixel = new Cell *[height];
	for( int i = 0; i < this->height; i++ ){
		this->pixel[i] = new Cell[this->width];
	}
}

Canvas::~Canvas( void ){
	for( int i = 0; i < this->height; i++ ){
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
