#include "cell.hpp"

Cell::Cell( void ){
	this->state = 0;
	this->prev_state = 0;
}

Cell::Cell( bool current_val, bool prev_val ){
	this->state = current_val;
	this->prev_state = prev_val;
}

void Cell::set_alive( bool value ){
	this->state = value;	
}

void Cell::set_next( bool next_val ){
	this->next_state = next_val;
}

void Cell::update( void ){
	this->prev_state = this->state;
	this->state = this->next_state;
	this->next_state = false;
	this->incrementAge(1);
}

bool Cell::is_alive( void ){
	return this->state;
}

void Cell::incrementAge( int ageIncrement ){
	this->age += ageIncrement;
}
