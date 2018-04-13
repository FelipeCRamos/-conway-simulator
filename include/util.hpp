#ifndef UTILS_HPP_
#define UTILS_HPP_
#include <iostream>

class Cell{
	private:
		int age; 	// how many generations that cell is alive
		bool state; // tells if the cell is alive or not
	public:
		void set_alive( bool );
		bool is_alive( void );
		void incrementAge( int );
};

#endif
