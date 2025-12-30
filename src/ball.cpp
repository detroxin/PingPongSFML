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
void Ball::reboundBat()
{
    m_DirectionX = -m_DirectionX;
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