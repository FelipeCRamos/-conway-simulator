#ifndef GENERATION_HPP_
#define GENERATION_HPP_

#include <iostream>
#include "util.hpp"
#include "canvas.hpp"
#include <chrono>
#include <random>

class Borders{
	public:
		int xmin = -1, xmax = 1;
		int ymin = -1, ymax = 1;
};

class Gen{
	private:
		Canvas *screen;
		Canvas *n_screen;
		int age = 0;
	public:
		void create( const int ); // will create an generation
		void update( void ); 
		void free( void );
		void next( void ); // will update generation
		void random_it( void );
		void print( char, char, char );
		int check_nearby( int, int );
		Borders *correct_borders( int, int, Borders *);
};

#endif
