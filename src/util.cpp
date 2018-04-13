#include "util.hpp"

// CELL SECTION
void Cell::set_alive( bool value ){
	this->state = value;	
}

void Cell::set_next( bool value ){
	this->next_state = value;
}

void Cell::update( void ){
	this->state = this->next_state;
}

bool Cell::is_alive( void ){
	return this->state;
}
	
void Cell::incrementAge( int ageIncrement ){
	this->age += ageIncrement;
}
