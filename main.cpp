#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), L"PingPong", sf::Style::Default);

    window.setVerticalSyncEnabled(true);

    sf::Font bitFont("bit5x3.ttf");

    sf::Text scoreText(bitFont);

    scoreText.setString("0 | 0");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition({400, 0});

    sf::FloatRect textRect = scoreText.getLocalBounds();
    scoreText.setOrigin(textRect.getCenter());
    scoreText.setPosition({800 / 2, 25});

    sf::CircleShape shape(75.f, 6);
    shape.setOrigin(shape.getGeometricCenter());
    shape.setPosition({400, 300});
    shape.setFillColor(sf::Color::White);

    sf::Clock clock;

    while(window.isOpen()) 
    {
        while(auto event = window.pollEvent()) 
        {
            if(event->is<sf::Event::Closed>()) 
            {
                window.close();
            } 
            else if(auto keyPressed = event->getIf<sf::Event::KeyPressed>()) 
            {
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }
            }
        }

        

        sf::Time dt = clock.restart();

        window.clear(sf::Color::Black);

        window.draw(shape);
        window.draw(scoreText);

        window.display();

        shape.rotate(sf::degrees(1.0f));
    }
}
