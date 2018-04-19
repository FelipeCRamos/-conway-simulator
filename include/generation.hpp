#ifndef GENERATION_HPP_
#define GENERATION_HPP_

#include <iostream>
#include <chrono>
#include <random>
#include <functional>
#include <fstream>
#include <sstream>

#include "cell.hpp"
#include "canvas.hpp"
#include "sha256.hpp"

class Borders{
	public:
		int xmin = -1, xmax = 1;
		int ymin = -1, ymax = 1;
};

class Gen{
	public:
		Canvas *screen;
		size_t age = 0;

		Gen( const int );
		Gen( const int, const int );
		~Gen( void );

		// Updating generation functions
		void next( void );
		void update( void );
		
		// Hashing related functions
		std::string hash( void );
		bool check_hash( std::vector<std::string> &hash_table, std::string current_hash, size_t min_times, size_t &counter );

		// Pseudo random generate a generation
		void random_it( void );

		// Print using <sep>, <alive_cell>, <dead_cell>
		void print( char, char, char );

		// Counting related functions
		size_t count_alives( void );
		int check_nearby( int, int );
		Borders *correct_borders( int, int, Borders *);
};

#endif
