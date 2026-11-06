#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <functional>


using namespace std;
void drawGraph(sf::RenderWindow& window, function<float(float)> func,
    float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LineStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x);                 // вычисление значения функции

        float screenX = 400 + x * scaleX;  // преобразование координат в экранные
        float screenY = 300 - y * scaleY;

        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main() {

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		return -1;
	}
    sf::RenderWindow window(sf::VideoMode(800, 600), "Schedule");
    sf::CircleShape userPoint(5);          // пользовательская точка, радиус 5 пикселей
    userPoint.setFillColor(sf::Color::Green);
    bool userPointExists = false;

    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);
    coordinatesText.setString("Coordinates: (0, 0)");
    // 2 _ Текст для отображения координат: размер 20, позиция (10,10), цвет белый,
    //     переменная coordinatesText (допишите код)

    // Оси X и Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300);   xAxis[0].color = sf::Color::White;
    xAxis[1].position = sf::Vector2f(750, 300);  xAxis[1].color = sf::Color::White;
    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50);   yAxis[0].color = sf::Color::White;
    yAxis[1].position = sf::Vector2f(400, 550);  yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Преобразование экранных координат в «математические»
                    float mathX = (mousePos.x - 400) / 30.0f;
                    float mathY = -(mousePos.y - 300) / 30.0f;

                    userPoint.setPosition(mousePos.x - userPoint.getRadius(),
                        mousePos.y - userPoint.getRadius());
                    userPointExists = true;

                    float e = 0.1f;
                    string o = " ";
                    string s = "region";
                    if (abs(mathX - mathY) < e) {
                        s = "schedule";
                    }
                    else if (mathY > mathX && mathY > -mathX) {
                        o = " 1 ";
                    }
                    else if (mathY < mathX && mathY < -mathX) {
                        o = " 3 ";
                    }
                    else if (mathY < mathX && mathY > -mathX) {
                        o = " 2 ";
                    }
                    else if (mathY > mathX && mathY < -mathX) {
                        o = " 4 ";
                    }
                    // 3 _ Допишите логику проверки точки по mathX и mathY!

                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) +
                        ", " + std::to_string(mathY) + ")" + "   >   " + s + o);
                }
            }
        }
        window.clear();
        // 4 _ Очистка экрана (допишите код)

        window.draw(xAxis);
        window.draw(yAxis);

        // 5 _ Замените на графики вашего варианта
        drawGraph(window, [](float x) { return -x; }, -10, 10, 30, 30, sf::Color::Blue);
        drawGraph(window, [](float x) { return x; }, -10, 10, 30, 30, sf::Color::Red);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        window.display();
    }

    return 0;
}
