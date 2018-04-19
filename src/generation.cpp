#include "generation.hpp"
#include "canvas.hpp"

Gen::Gen( const int SIZE ){
	// Gen Constructor that creates an bidimensional canvas size * size.
	this->screen = new Canvas(SIZE, SIZE);
}

Gen::Gen( const int height, const int width ){
	// Gen Constructor that creates an bidimensional canvas height * width
	this->screen = new Canvas(height, width);
}

Gen::~Gen( void ){
	// Gen destructor
	delete this->screen;
}

void Gen::next( void ){
	int nearby_c = 0; 	// A simple counter variable, to simplify things

	for( int i = 0; i < this->screen->height; i++ ){
		for( int j = 0; j < this->screen->width; j++ ){
			this->screen->pixel[i][j].nearby = check_nearby( i, j );	
			nearby_c = this->screen->pixel[i][j].nearby;
			bool is_alive = screen->pixel[i][j].is_alive();

			if( nearby_c <= 1 )
			{
				this->screen->pixel[i][j].set_next(false); // cell dies
			}

			else if( nearby_c >= 4 and is_alive == true)
			{
				this->screen->pixel[i][j].set_next(false); // cell dies
			}

			else if( (nearby_c == 2 or nearby_c == 3) and is_alive == true)
			{
				this->screen->pixel[i][j].set_next(true); // cell remains alive
			}

			else if( is_alive == false and nearby_c == 3 )
			{
				this->screen->pixel[i][j].set_next(true); // cell borns
			}
	
			else
			{
				this->screen->pixel[i][j].set_next(false); // cell remains dead
			}
		}
	}
	this->update(); 	// With all the math done, we can update the generation
}

void Gen::update( void ){
	for( int i = 0; i < this->screen->height; i++ ){
		for( int j = 0; j < this->screen->width; j++ ){
			// This will update actual value of the cell to the next value
			this->screen->pixel[i][j].update();
		}
	}
}

void Gen::random_it( void ){
	std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
	for(int i = 0; i < this->screen->height; i++){
		for(int j = 0; j < this->screen->width; j++){
			// create a random number between [0,1]
			this->screen->pixel[i][j].set_alive( random() % 2 );
		}
	}
}


std::string Gen::hash( void ){
	// useful variables to simplify the code
	int m_height = this->screen->height;
	int m_width= this->screen->width;
	int size = m_height * m_width;

	// the key to the sha256
	char *seed = new char[size];
	
	// populate the seed
	for( int i = 0; i < m_height; i++ ){
		for( int j = 0; j < m_width; j++ ){
			int value = this->screen->pixel[i][j].is_alive();
			if( value == 0 ){
				seed[i * m_height + j] = 'd'; // random char, i've choosen d
			} else {
				seed[i * m_height + j] = 'a'; // random char, i've choosed a
			}
		}
	}
	std::string gen_hash = sha256(seed); 	// creates the SHA256 hash itself

	delete[] seed;
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
		!( height <= 0 and height >= screen->height - 1 ) or \
		( width <= 0 and width >= screen->width - 1 ) )
	{
		border = correct_borders( height, width, border );
	}

	for( int i = border->ymin; i <= border->ymax; i++ ){
		for( int j = border->xmin; j <= border->xmax; j++ ){
			if( !(i == 0 and j == 0) )
			{
				if( screen->pixel[height+i][width+j].is_alive() == true )
					count++;
			}
		}
	}	

	delete border;
	return count;
}

size_t Gen::count_alives( void ){
	size_t counter = 0;
	for( int i = 0; i < this->screen->height; i++ ){
		for( int j = 0; j < this->screen->width; j++ ){
			if( this->screen->pixel[i][j].is_alive() ){
				counter++;
			}
		}
	}
	return counter;
}
