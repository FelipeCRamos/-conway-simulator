#include "utils.hpp"

void Cell::alive( bool value ){
	state = value;	
}

bool Cell::isalive( void ){
	return state;
}
	
void Cell::set_pos( int xpos, int ypos ){
	x = xpos;
	y = ypos;
}
void Cell::incrementAge( int ageIncrement ){
	age += ageIncrement;
}
