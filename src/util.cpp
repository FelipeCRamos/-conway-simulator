#include "util.hpp"

// CELL SECTION
void Cell::set_alive( bool value ){
	state = value;	
}

bool Cell::is_alive( void ){
	return state;
}
	
void Cell::incrementAge( int ageIncrement ){
	age += ageIncrement;
}
