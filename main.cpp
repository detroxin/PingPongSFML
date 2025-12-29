#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode({800, 600}), L"PingPong", Style::Default);

    window.setVerticalSyncEnabled(true);

    CircleShape shape(100.f, 3);
    shape.setOrigin(shape.getGeometricCenter());
    shape.setPosition({400, 300});
    shape.setFillColor(Color::White);

    while(window.isOpen()) {
        while(auto event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) {
                window.close();
            } else if(auto keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }

        window.clear(Color::Black);
        window.draw(shape);
        window.display();
        shape.rotate(degrees(1.0f));
    }
}
