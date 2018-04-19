#include "generation.hpp"
#include "canvas.hpp"

/*!
 * \file Generation.cpp
 * \brief Contains all the implementations of Gen class object.
 * \author Felipe Ramos
 */
/*!
 * \brief Gen object constructor that recieves a unique size, creating a size*size
 * array
 */
Gen::Gen( const int SIZE ){
	// Gen Constructor that creates an bidimensional canvas size * size.
	this->screen = new Canvas(SIZE, SIZE);
}

/*!
 * \brief Another Gen constructor, but it recieves two arguments and create a (x,y) 
 * bidimensional Canvas object
 * \param const int height : The height of the bidimensional Canvas object
 * \param const int width : The width of the bidimensional Canvas object
 */
Gen::Gen( const int height, const int width ){
	// Gen Constructor that creates an bidimensional canvas height * width
	this->screen = new Canvas(height, width);
}

/*!
 * \brief Gen object destructor
 */
Gen::~Gen( void ){
	// Gen destructor
	delete this->screen;
}

/*!
 * \brief Gen object next function, it's resposible for generating and updating
 * for the next generation (configuration).
 */
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

/*!
 * \brief Used inside the ``Gen::next()` function, it's responsible for update
 * Cell object to the next value
 */
void Gen::update( void ){
	for( int i = 0; i < this->screen->height; i++ ){
		for( int j = 0; j < this->screen->width; j++ ){
			// This will update actual value of the cell to the next value
			this->screen->pixel[i][j].update();
		}
	}
}

/*!
 * \brief It will populate a generation with pseudo random values
 */
void Gen::random_it( void ){
	std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
	for(int i = 0; i < this->screen->height; i++){
		for(int j = 0; j < this->screen->width; j++){
			// create a random number between [0,1]
			this->screen->pixel[i][j].set_alive( random() % 2 );
		}
	}
}


/*!
 * \brief A Gen object function that will generate a SHA256 hash for each
 * generation, in order to check stability of the current Gen, comparing it's hash with the
 * hash table list.
 */
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

/*!
 * \brief This function will check if a given hash, in a given hash table
 * will occur a minimum of times counted by a counter.
 * \param std::vector<std::string> &hash_table : The vector that will store all
 * hash tables already used.
 * \param std::string current_hash : The current hash that we're comparing to 
 * see if we can found another min_times equal hash.
 * \param size_t min_times : The minimum of times that we need to find a given
 * hash to tick the flag.
 * \param size_t &counter : A counter referenced variable to check the min_times
 */
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

/*!
 * \brief A print function that will call for Canvas object print function
 * \param char sep : A separator char that will be used between alive and dead
 * cells
 * \param char alive_c : The alive representation char
 * \param char dead_c : The dead representation char
 */
void Gen::print( char sep, char alive_c, char dead_c ){
	screen->print(sep, alive_c, dead_c);
}

/*!
 * \brief A secure function to make sure that when checking nearby cells, we
 * dont throw a seg fault error (trying to acess anything beyond the size of
 * the bimensional array)
 * \param int height : The height of current generation to check bounds
 * \param int width : The width of current generation to check bounds
 * \param Borders *fix_border : the output borders to further math functions
 */
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

/*!
 * \brief A function to check how many nearby cells are alive
 * \param int height : Generation height, needed to make the corrections
 * \param int width : Generation width, needed to make the corrections
 */
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

/*!
 * \brief Alive cells counter
 * \return A size_t value of alive cells in the entire generation
 */
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
