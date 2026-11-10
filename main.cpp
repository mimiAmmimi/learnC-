#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Variant 1");
    sf::RectangleShape cells[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
			cells[i][j].setSize(sf::Vector2f(50, 50));
            cells[i][j].setPosition(j * 50, i * 50);
            cells[i][j].setOutlineColor(sf::Color::White);
            cells[i][j].setOutlineThickness(-1.f);

            if (i >= 4 && i <= 8 && j >= (i - 4) && j <= (9 - (i - 4))) {
				cells[i][j].setFillColor(sf::Color::Green);
            }
            else {
				cells[i][j].setFillColor(sf::Color::Black);
            }
         }
    }
    while (window.isOpen()) {
        sf::Event event;
        window.clear();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				window.draw(cells[i][j]);
			}
		}
		window.display();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
    }

    return 0;
}