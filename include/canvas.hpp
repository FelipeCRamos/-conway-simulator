#ifndef CANVAS_HPP_
#define CANVAS_HPP_
#include <iostream>
#include "cell.hpp"

/*!
 * \file Canvas.hpp
 * \brief Canvas object related lib
 * \author Felipe Ramos
 */

/*!
 * \brief Class to store all the Cell objects, like a real canvas.
 */
class Canvas{
	public:
		Canvas( int, int );
		~Canvas( void );
		int width;
		int height;
		Cell **pixel;
		void print( char, char, char );
};

#endif
