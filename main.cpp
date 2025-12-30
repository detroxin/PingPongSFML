#include "bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), L"PingPong", sf::Style::Default);

    window.setVerticalSyncEnabled(true);

    /*
    ******************************
                HUD
    ******************************
    */

    //sf::Font bitFont("data/fonts/bit5x3.ttf");
    sf::Font digitalFont("data/fonts/digital_7.ttf");
    //sf::Font dsDigitFont("data/fonts/DS-DIGIT.ttf");

    sf::Text scoreText(digitalFont);

    scoreText.setString("0 | 0");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    //scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition({400, 0});

    sf::Text escText(digitalFont);

    escText.setString("Press Esc for close...");
    escText.setCharacterSize(16);
    escText.setFillColor(sf::Color::White);
    //escText.setStyle(sf::Text::Bold);
    escText.setPosition({0, 0});

    sf::FloatRect textRect = scoreText.getLocalBounds();
    scoreText.setOrigin(textRect.getCenter());
    scoreText.setPosition({800 / 2, 25});
    /*
    ******************************
                GAME
    ******************************
    */

    int scoreLeftPlayer{0};
    int scoreRightPlayer{0};

    Bat leftBat(20, 600 / 2);
    Bat rightBat(800 - 20, 600 / 2);

    sf::Clock clock;

    while(window.isOpen()) 
    {
        /*
        ******************************
                    INPUT
        ******************************
        */
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

                //LEFT BAT
                if(keyPressed->scancode == sf::Keyboard::Scancode::W)
                {
                    leftBat.moveUp();
                }
                else
                {
                    leftBat.stopUp();
                }

                if(keyPressed->scancode == sf::Keyboard::Scancode::S)
                {
                    leftBat.moveDown();
                }
                else
                {
                    leftBat.stopDown();
                }

                //RIGHT BAT
                if(keyPressed->scancode == sf::Keyboard::Scancode::Up)
                {
                    rightBat.moveUp();
                }
                else
                {
                    rightBat.stopUp();
                }

                if(keyPressed->scancode == sf::Keyboard::Scancode::Down)
                {
                    rightBat.moveDown();
                }
                else
                {
                    rightBat.stopDown();
                }
            }
        }

        /*
        ******************************
                    UPDATE
        ******************************
        */
        

        sf::Time dt = clock.restart();
        leftBat.update(dt);
        rightBat.update(dt);

        std::stringstream ss;
        ss << scoreLeftPlayer << " | " << scoreRightPlayer;
        scoreText.setString(ss.str());

        /*
        ******************************
                    DRAW
        ******************************
        */

        window.clear(sf::Color::Black);

        window.draw(scoreText);
        window.draw(escText);
        window.draw(leftBat.getShape());
        window.draw(rightBat.getShape());

        window.display();
    }
}
