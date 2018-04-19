#include "canvas.hpp"

/*!
 * \file Canvas.cpp
 * \brief The implementation of all Canvas.hpp functions
 * \author Felipe Ramos
 */

/*!
 * \brief Canvas object constructor that takes width and height parameters
 * \param int x : Width parameter
 * \param int y : Height parameter
 */
Canvas::Canvas( int x, int y ){
	this->width = x;
	this->height = y;

	// then, we allocate the canvas
	this->pixel = new Cell *[height];
	for( int i = 0; i < this->height; i++ ){
		this->pixel[i] = new Cell[this->width];
	}
}

/*!
 * \brief Canvas object destructor
 */
Canvas::~Canvas( void ){
	for( int i = 0; i < this->height; i++ ){
		delete[] this->pixel[i];
	}
	delete[] this->pixel;
}

/*!
 * \brief Prints the Canvas object with the specified parameters
 * \param char separator : it's the separator between alive and dead cells
 * \param char alive_c : The representation of an alive cell
 * \param char dead_c : The representation of an dead cell
 * \return void
 */
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
