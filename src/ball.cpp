#include "ball.h"
// This the constructor function
Ball::Ball(float startX, float startY) : m_Position(startX,startY)
{   
    m_Shape.setSize(sf::Vector2f(10, 10));
    m_Shape.setPosition(m_Position);
}

sf::FloatRect Ball::getPosition()
{
    return m_Shape.getGlobalBounds();
}
sf::RectangleShape Ball::getShape()
{
    return m_Shape;
}
float Ball::getXVelocity()
{
    return m_DirectionX;
}

void Ball::reboundUpOrBottom()
{
    m_DirectionY = -m_DirectionY;
}
void Ball::reboundBat(RandomGenerator& rng)
{
    m_Speed = rng.getNextRandomNumber(1100, 2300);
    m_DirectionX = -m_DirectionX;

    int randomFactor = rng.getNextRandomNumber(0, 250); 

    float yOffsetFactor = (randomFactor / 1000.0f);
    
    if (std::abs(m_DirectionY) < 0.1f) {
        m_DirectionY = (m_DirectionY > 0) ? 0.1f : -0.1f;
    }

    m_DirectionY = (m_DirectionY > 0) ? yOffsetFactor : -yOffsetFactor;
}
void Ball::reboundLeftOrRight()
{
    m_Position.y = 300;
    m_Position.x = 400;
    m_DirectionX = -m_DirectionX;
}

void Ball::update(sf::Time dt)
{
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
    m_Shape.setPosition(m_Position);
}