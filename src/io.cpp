#include "io.hpp"

Gen *parse( std::ifstream &config_file ){
	std::string buf;
	size_t line_counter = 0;

	int h, w;
	std::vector<int> values;
	char alive;

	while(config_file.good())
	{
		std::getline(config_file, buf);
		std::stringstream line(buf);	
		char cell;
		if( line_counter == 0 )
		{
			line >> h >> w;
		}
		else if( line_counter == 1 )
		{
			line >> alive;
		}
		else
		{
			size_t index=0;
			while( line.get(cell) ) {
				// now, let's get individual chars
				if(index++ < w){
					if( cell == alive ){
						values.push_back(1);
					} else if( cell != '\n' and cell != '\0' ){
						values.push_back(0);
					}
				}
			}
		}
		line_counter++;
	}

	// now, vector is populated and with all values loaded from the file

	Gen *load_gen = new Gen(h, w);
		
	for( int i = 0; i < load_gen->screen->height; i++ ){
		std::cout << "CONFIG: ";
		for( int j = 0; j < load_gen->screen->width; j++ ){
			std::cout << values[i * h + j] << " ";
			load_gen->screen->pixel[i][j].set_alive( values[i * h + j] );
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return load_gen;
}
