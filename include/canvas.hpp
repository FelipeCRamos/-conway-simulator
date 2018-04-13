#ifndef CANVAS_HPP_
#define CANVAS_HPP_
#include <iostream>
#include "util.hpp"

class Canvas{
	public:
		int width;
		int height;
		Cell **screen;
		void create_screen( int, int );
		void free_screen( void );
		void print( char );
		void next_gen( long int * );
};

#endif