#ifndef GENERATION_HPP_
#define GENERATION_HPP_

#include <iostream>
#include "cell.hpp"
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
		std::hash<Canvas *> ha;
		// TODO: Create and store hash for future comparisson
		int age = 0;
	public:
		Gen( const int );
		~Gen( void );
		// void create( const int ); // will create an generation
		// void free( void );

		bool next( void ); // will update generation
		void update( void ); 
		void generate_hash( void );
		size_t acess_hash( void );
		void random_it( void );
		void print( char, char, char );

		bool is_stable( int, int );
		int check_nearby( int, int );
		Borders *correct_borders( int, int, Borders *);
};

#endif
