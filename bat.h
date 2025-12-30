#pragma once
#include <SFML/Graphics.hpp>

class Bat
{
private:
    sf::Vector2f m_Position;
    sf::RectangleShape m_Shape;
    float m_Speed = 650.0f;
    bool m_MovingDown = false;
    bool m_MovingUp = false;
public:
    Bat(float startX, float startY);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void moveUp();
    void moveDown();
    void stopUp();
    void stopDown();
    void update(sf::Time dt);
};