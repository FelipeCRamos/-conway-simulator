#ifndef UTILS_HPP_
#define UTILS_HPP_
#include <iostream>

class Cell{
	private:
		int age; 	// how many generations that cell is alive
		bool state; // tells if the cell is alive or not
		bool prev_state;
		bool next_state; 
	public:
		int nearby;
		void init_alive( bool, bool );
		void set_alive( bool );
		bool set_next( bool, bool );
		void update( void );
		bool is_alive( void );
		void incrementAge( int );
};

#endif
