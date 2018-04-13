#include "generation.hpp"
#include "canvas.hpp"

void Gen::create( const int SIZE ){
	// A simple constructor function
	this->screen = new Canvas;
	this->screen->create_screen(SIZE, SIZE);
}

void Gen::free( void ){
	this->screen->free_screen();
	delete this->screen;
}

void Gen::next( void ){
	int counter = 0;
	for( int i = 0; i < this->screen->height; i++ ){
		for( int j = 0; j < this->screen->width; j++ ){
			counter = check_nearby( i, j );	
			bool is_alive = screen->pixel[i][j].is_alive();

			if( counter <= 1 ){
				// cell dies
				// std::cout << "cell dies" << std::endl;
				this->screen->pixel[i][j].set_next(false);
			}

			else if( counter >= 4 and is_alive == true){
				// cell dies
				// std::cout << "cell dies" << std::endl;
				this->screen->pixel[i][j].set_next(false);
			}

			else if( (counter == 2 or counter == 3) and is_alive == true){
				// cell remains alive
				// std::cout << "cell lives" << std::endl;
				this->screen->pixel[i][j].set_next(true);
			}

			else if( is_alive == false and counter == 3 ){
				// cell borns
				// std::cout << "cell lives" << std::endl;
				this->screen->pixel[i][j].set_next(true);
			}
	
			else {
				// cell remains dead
				this->screen->pixel[i][j].set_next(false);
			}
		}
	}
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
	for(int i = 0; i < screen->height; i++){
		for(int j = 0; j < screen->width; j++){
			screen->pixel[i][j].set_alive(random() % 2);
		}
	}
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

	if( !(height <= 0 and height >= screen->height-1) or (width <= 0 and width >= screen->width-1) ){
		border = correct_borders( height, width, border );
	}

	for( int i = border->ymin; i <= border->ymax; i++ ){
		for( int j = border->xmin; j <= border->xmax; j++ ){
			if( i == 0 and j == 0 ){
				// std::cout << "\e[1;4m\x1b[32m" << screen->pixel[height+i][width+j].is_alive() << "\e[0m\x1b[0m ";
			} else{
				if( screen->pixel[height+i][width+j].is_alive() == true )
					count++;
				// std::cout << screen->pixel[height+i][width+j].is_alive() << " ";
			}
		}
		// std::cout << std::endl;
	}	
	// std::cout << "Returning count: " << count << std::endl;

	delete border;
	return count;
}
