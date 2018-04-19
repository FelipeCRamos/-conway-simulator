#include <SFML/Graphics.hpp>
int main(void){
	sf::RenderWindow window(sf::VideoMode(1000,1000), "Conway's Game of Life Simulator");
	sf::CircleShape shape(500.f);
	shape.setFillColor(sf::Color::Green);
	while( window.isOpen() ){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
}
