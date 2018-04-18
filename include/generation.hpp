#ifndef GENERATION_HPP_
#define GENERATION_HPP_

#include <iostream>
#include <chrono>
#include <random>
#include <functional>

#include "cell.hpp"
#include "canvas.hpp"
#include "sha256.hpp"

class Borders{
	public:
		int xmin = -1, xmax = 1;
		int ymin = -1, ymax = 1;
};

class Gen{
	private:
		Canvas *screen;
	public:
		size_t age = 0;

		Gen( const int );
		~Gen( void );
		// void create( const int ); // will create an generation
		// void free( void );

		void next( void ); 		// will update generation
		void update( void );
		
		// Hashing related functions
		std::string hash( void );
		bool check_hash( std::vector<std::string> &hash_table, std::string current_hash, size_t min_times, size_t &counter );

		void random_it( void );
		void print( char, char, char );

		bool is_stable( int, int );
		int check_nearby( int, int );
		Borders *correct_borders( int, int, Borders *);
};

#endif
