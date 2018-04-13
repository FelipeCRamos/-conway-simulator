#include "cell.hpp"

Cell::Cell( void ){
	this->state = 0;
	this->prev_state = 0;
}

Cell::Cell( bool current_val, bool prev_val ){
	this->state = current_val;
	this->prev_state = prev_val;
}

void Cell::rand_alive( bool value, bool prev ){
	this->state = value;
	this->prev_state = prev;
}

void Cell::set_alive( bool value ){
	this->state = value;	
}

bool Cell::set_next( bool next_val, bool had_changed_flag ){
	if( this->state == next_val or this->prev_state == next_val ){
		// then, the element is cicling through states
		this->next_state = next_val;
		// And we will return the current flag,
		// since he basically didn't changed
		return had_changed_flag; 
	} else {
		this->next_state = next_val;
		return true;	// Then, it has changed!
	}
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
