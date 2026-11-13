#include <SFML/Graphics.hpp>

int main() {
    constexpr int N = 10;
    constexpr int size = 50;
    constexpr int start = N / 2 - 1;
    constexpr int end = N - 2;

    sf::RenderWindow window(sf::VideoMode(N * size, N * size), "Variant 1");
    sf::RectangleShape cells[N][N];

    for (int i = 0; i < N; i++) {
        const int skip = i - start;

        for (int j = 0; j < N; j++) {
            cells[i][j].setSize(sf::Vector2f(size, size));
            cells[i][j].setPosition(j * size, i * size);
            cells[i][j].setOutlineColor(sf::Color::White);
            cells[i][j].setOutlineThickness(-1.f);

            if (i >= start && i <= end &&
                j >= skip && j < N - skip) {
                cells[i][j].setFillColor(sf::Color::Green);
            } else {
                cells[i][j].setFillColor(sf::Color::Black);
            }
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        window.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
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
