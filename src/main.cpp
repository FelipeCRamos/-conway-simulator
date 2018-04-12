#include <iostream>
#include "utils.hpp"

int main( int argc, char **argv ) {
	int canvas = 30;
	int pow_canvas = canvas * canvas;
	Cell *screen = new Cell[ pow_canvas ];
	for( int i = 0; i < canvas; i++ ){
		for( int j = 0; j < canvas; j++){
			if(j % 2 == 0)
				screen[ i * canvas + j ].alive(true);
			else
				screen[ i * canvas + j ].alive(false);
		}
	}

	for( int i = 0; i < canvas; i++ ){
		for( int j = 0; j < canvas; j++){
			std::cout << screen[ i*canvas + j ].isalive() << " ";	
		}
		std::cout << std::endl;
	}
	
	return 0;
}
