#include "cell.hpp"

/*!
 * \file Cell.cpp
 * \brief The Cell class functions implementation
 * \author Felipe Ramos
 */

/*!
 * \brief Cell object constructor
 */
Cell::Cell( void ){
	this->state = 0;
	this->prev_state = 0;
}

/*!
 * \brief Cell object function that sets the current state and previous state of
 * the cell
 * \param bool current_val : the current value that will be set
 * \param bool prev_val : the previous value that will be set
 */
Cell::Cell( bool current_val, bool prev_val ){
	this->state = current_val;
	this->prev_state = prev_val;
}

/*!
 * \brief Cell object function that sets the current state of the cell
 * \param bool value : That's will be the bool value that the cell will recieve
 */
void Cell::set_alive( bool value ){
	this->state = value;	
}

/*!
 * \brief Cell object function that sets the next value that the cell will have
 * \param bool next_val : The next value that the cell will have
 */
void Cell::set_next( bool next_val ){
	this->next_state = next_val;
}

/*!
 * \brief Cell object function that is responsible to update current cell state
 * to next cell state.
 */
void Cell::update( void ){
	this->prev_state = this->state;
	this->state = this->next_state;
	this->next_state = false;
	this->incrementAge(1);
}

/*!
 * \brief Cell object function that will tell if a Cell is alive
 */
bool Cell::is_alive( void ){
	return this->state;
}

/*! 
 * \brief Cell object function that will increment Cell.age by a given number
 * \param int ageIncrement : The number that will be += to the actual number
 */
void Cell::incrementAge( int ageIncrement ){
	this->age += ageIncrement;
}
