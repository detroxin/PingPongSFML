#include "bat.h"

Bat::Bat (float startX, float startY) : m_Position(startX, startY)
{
    m_Shape.setSize(sf::Vector2f(5, 50));
    m_Shape.setPosition(m_Position);
    
}

sf::FloatRect Bat::getPosition()
{
    return m_Shape.getGlobalBounds();
}
    
sf::RectangleShape Bat::getShape()
{
    return m_Shape;
}
    
void Bat::moveUp()
{
    m_MovingUp = true;
}
   
void Bat::moveDown()
{
    m_MovingDown = true;
}
    
void Bat::stopUp()
{
    m_MovingUp = false;
}
    
void Bat::stopDown()
{
    m_MovingDown = false;
}
   
void Bat::update(sf::Time dt)
{
    if (m_MovingUp)
    {
        m_Position.y -= m_Speed * dt.asSeconds();
    }
    if (m_MovingDown)
    {
        m_Position.y += m_Speed * dt.asSeconds();
    }

    m_Shape.setPosition(m_Position);
}