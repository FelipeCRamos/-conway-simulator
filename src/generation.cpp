#include "generation.hpp"
#include "canvas.hpp"

Gen::Gen( const int SIZE ){
	// Object Gen Constructor that creates an bidimensional canvas size * size.
	this->screen = new Canvas(SIZE, SIZE);
}

Gen::~Gen( void ){
	// Object Gen destructor
	delete this->screen;
}

void Gen::next( void ){
	int nearby_counter = 0; 	// A simple counter variable, to simplify things

	for( int i = 0; i < this->screen->height; i++ ){
		for( int j = 0; j < this->screen->width; j++ ){
			this->screen->pixel[i][j].nearby = check_nearby( i, j );	
			nearby_counter = this->screen->pixel[i][j].nearby;
			bool is_alive = screen->pixel[i][j].is_alive();

			if( nearby_counter <= 1 ){
				// cell dies
				this->screen->pixel[i][j].set_next(false);
			}

			else if( nearby_counter >= 4 and is_alive == true){
				// cell dies
				this->screen->pixel[i][j].set_next(false);
			}

			else if( (nearby_counter == 2 or nearby_counter == 3) and is_alive == true){
				// cell remains alive
				this->screen->pixel[i][j].set_next(true);
			}

			else if( is_alive == false and nearby_counter == 3 ){
				// cell borns
				this->screen->pixel[i][j].set_next(true);
			}
	
			else {
				// cell remains dead
				this->screen->pixel[i][j].set_next(false);
			}
		}
	}

	// calls the updater
	this->update();
}

void Gen::update( void ){
	for( int i = 0; i < this->screen->height; i++ ){
		for( int j = 0; j < this->screen->width; j++ ){
			this->screen->pixel[i][j].update();
		}
	}
}

void Gen::random_it( void ){
	std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
	for(int i = 0; i < this->screen->height; i++){
		for(int j = 0; j < this->screen->width; j++){
			this->screen->pixel[i][j].set_alive( random() % 2 );
		}
	}
}


std::string Gen::hash( void ){
	// useful variables to simplify the code
	int m_height = this->screen->height;
	int m_width= this->screen->width;

	int size = m_height * m_width;
	char *seed = new char[size];
	
	// populate the seed
	for( int i = 0; i < m_height; i++ ){
		for( int j = 0; j < m_width; j++ ){
			int value = this->screen->pixel[i][j].is_alive();
			if( value == 0 ){
				seed[i * m_height + j] = 'd';
			} else {
				seed[i * m_height + j] = 'a';
			}
		}
	}
	std::string gen_hash = sha256(seed);
	// size_t gen_hash = std::hash<char*>{}(seed);
	delete[] seed;

	// return gen_hash; // STUB
	return gen_hash;
}

bool Gen::check_hash( std::vector<std::string> &hash_table, std::string current_hash, size_t min_times, size_t &counter )
{
	for( auto i = hash_table.begin(); i != hash_table.end(); i++ ){
		if(current_hash == *i){
			counter++;
			if( counter == min_times ){
				return true;
			}
		}	
	}
	return false;
}

void Gen::print( char sep, char alive_c, char dead_c ){
	screen->print(sep, alive_c, dead_c);
}

Borders *Gen::correct_borders(  int height, int width, Borders *fix_border ){
	
	if( height == 0 )
		fix_border->ymin = 0;
	if( width == 0 )
		fix_border->xmin = 0;
	if( height == screen->height-1 )
		fix_border->ymax = 0;
	if( width == screen->width-1 )
		fix_border->xmax = 0;

	return fix_border;
}

int Gen::check_nearby( int height, int width ){
	Borders *border = new Borders;
	int count = 0;

	if(
		!( height <= 0 and height >= screen->height - 1 ) or 
		( width <= 0 and width >= screen->width - 1 )
	){
		border = correct_borders( height, width, border );
	}

	for( int i = border->ymin; i <= border->ymax; i++ ){
		for( int j = border->xmin; j <= border->xmax; j++ ){
			if( i == 0 and j == 0 ){
			} else{
				if( screen->pixel[height+i][width+j].is_alive() == true )
					count++;
			}
		}
	}	

	delete border;
	return count;
}
