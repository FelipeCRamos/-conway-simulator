#ifndef CELL_HPP_
#define CELL_HPP_
#include <iostream>

/*!
 * \file Cell.hpp
 * \brief Cell object related lib
 * \author Felipe Ramos
 */

/*!
 * \brief The Cell object, that represents a individual cell with some info about it
 */
class Cell{
	private:
		int age; 			/// how many generations that cell is alive
		bool state; 		/// tells if the cell is alive or not
		bool prev_state;
		bool next_state; 
	public:
		int nearby;

		Cell( void );

		Cell( bool, bool );

		void set_alive( bool );

		void set_next( bool );

		void update( void );

		void incrementAge( int );

		bool is_alive( void );
};

#endif
