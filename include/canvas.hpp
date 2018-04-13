#ifndef CANVAS_HPP_
#define CANVAS_HPP_
#include <iostream>
#include "cell.hpp"

class Canvas{
	public:
		Canvas( int, int );
		~Canvas( void );
		int width;
		int height;
		Cell **pixel;
		// void create_screen( int, int );
		// void free_screen( void );
		void print( char, char, char );
};

#endif
