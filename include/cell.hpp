#ifndef CELL_HPP_
#define CELL_HPP_
#include <iostream>

class Cell{
	private:
		int age; 			// how many generations that cell is alive
		bool state; 		// tells if the cell is alive or not
		bool prev_state;
		bool next_state; 
	public:
		int nearby;

		// Constructor
		Cell( void );
		Cell( bool, bool );

		void set_alive( bool );
		void set_next( bool );
		void update( void );
		void incrementAge( int );
		bool is_alive( void );
};

#endif
