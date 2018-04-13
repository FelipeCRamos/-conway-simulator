#include "generation.hpp"
#include "canvas.hpp"

void Gen::create( const int SIZE ){
	// A simple constructor function
	screen = new Canvas;
	screen->create_screen(SIZE, SIZE);
}

void Gen::free( void ){
	screen->free_screen();
	delete screen;
}

void Gen::next( void ){
	for( int i = 0; i < screen->height; i++ ){
		for( int j = 0; j < screen->width; j++ ){
			// std::cout << "Trying to acess " << i << "," << j << std::endl;
			check_nearby( i, j );
		}
	}
	// std::cout << "Sai!" << std::endl;
}

void Gen::random_it( void ){
	std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
	for(int i = 0; i < screen->height; i++){
		for(int j = 0; j < screen->width; j++){
			screen->screen[i][j].set_alive(random() % 2);
			// std::cout << random()%2 << std::endl;
		}
	}
}

void Gen::print( void ){
	screen->print(' ');
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


	border = correct_borders( height, width, border );
	if( !(height > 0 and height < screen->height) and !(width > 0 and width < screen->width) ){
		// if the element is on any border
	}
	for( int i = border->ymin; i <= border->ymax; i++ ){
		for( int j = border->xmin; j <= border->xmax; j++ ){
			if( screen->screen[height+i][width+j].is_alive() == true ){
				// if the cell is alive
				// std::cout << screen->screen[height+i][width+i].is_alive() << " ";
				count++;
			} else {
				// if the cell isn't alive
				// std::cout << screen->screen[height+i][width+i].is_alive() << " ";
			}
		}
		// std::cout << std::endl;
	}	
	// std::cout << std::endl;

	delete border;
	return count;
}
