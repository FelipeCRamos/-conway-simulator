#ifndef UTILS_HPP_
#define UTILS_HPP_
#include <iostream>

class Cell{
	private:
		int age; 	// how many generations that cell is alive
		bool state; // tells if the cell is alive or not
	public:
		int x, y; 	// position in matrix

		void alive( bool );
		bool isalive( void );
		void set_pos( int, int );
		void incrementAge( int );
};


#endif
