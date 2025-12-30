#include "bat.h"
#include "ball.h"
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

    sf::Text leftPlayerScoreText(digitalFont);
    sf::Text rightPlayerScoreText(digitalFont);

    leftPlayerScoreText.setString("0");
    leftPlayerScoreText.setCharacterSize(32);
    leftPlayerScoreText.setFillColor(sf::Color::White);
    leftPlayerScoreText.setPosition({25, 10});

    rightPlayerScoreText.setString("0");
    rightPlayerScoreText.setCharacterSize(32);
    rightPlayerScoreText.setFillColor(sf::Color::White);
    rightPlayerScoreText.setPosition({775, 10});

    sf::Text escText(digitalFont);

    escText.setString("Press Esc for close...");
    escText.setCharacterSize(16);
    escText.setFillColor(sf::Color::White);
    escText.setPosition({0, 570});

    /*
    ******************************
                AUDIO
    ******************************
    */

    sf::SoundBuffer reboundBuffer("data/sounds/rebound-sound.wav");
    sf::Sound reboundSound(reboundBuffer);

    /*
    ******************************
                GAME
    ******************************
    */

    int scoreLeftPlayer{0};
    int scoreRightPlayer{0};

    Bat leftBat(20, 600 / 2);
    Bat rightBat(800 - 20, 600 / 2);

    Ball ball(800 / 2, 600 / 2);

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

                if(keyPressed->scancode == sf::Keyboard::Scancode::S)
                {
                    leftBat.moveDown();
                }

                //RIGHT BAT
                if(keyPressed->scancode == sf::Keyboard::Scancode::Up)
                {
                    rightBat.moveUp();
                }

                if(keyPressed->scancode == sf::Keyboard::Scancode::Down)
                {
                    rightBat.moveDown();
                }
            }
            else if(auto keyPressed = event->getIf<sf::Event::KeyReleased>()) 
            {
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window.close();
                }

                //LEFT BAT
                if(keyPressed->scancode == sf::Keyboard::Scancode::W)
                {
                    leftBat.stopUp();
                }

                if(keyPressed->scancode == sf::Keyboard::Scancode::S)
                {
                    leftBat.stopDown();
                }

                //RIGHT BAT
                if(keyPressed->scancode == sf::Keyboard::Scancode::Up)
                {
                    rightBat.stopUp();
                }

                if(keyPressed->scancode == sf::Keyboard::Scancode::Down)
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
        ball.update(dt);

        leftPlayerScoreText.setString(std::to_string(scoreLeftPlayer));
        rightPlayerScoreText.setString(std::to_string(scoreRightPlayer));
        
        //BALL LOGIC
        if (ball.getPosition().position.y < 0 || 
            ball.getPosition().position.y + ball.getPosition().size.y > 600)
        {
            ball.reboundUpOrBottom();
        }

        if (ball.getPosition().position.x < 0)
        {
            scoreRightPlayer++;
            ball.reboundLeftOrRight();
        }
        if (ball.getPosition().position.x + ball.getPosition().size.x > 800)
        {
            scoreLeftPlayer++;
            ball.reboundLeftOrRight();
        }

        if (ball.getPosition().findIntersection(leftBat.getPosition()) || ball.getPosition().findIntersection(rightBat.getPosition()))
        {
            ball.reboundBat();
        }

        /*
        ******************************
                    DRAW
        ******************************
        */

        window.clear(sf::Color::Black);

        window.draw(leftPlayerScoreText);
        window.draw(rightPlayerScoreText);
        window.draw(escText);
        window.draw(leftBat.getShape());
        window.draw(rightBat.getShape());
        window.draw(ball.getShape());

        window.display();
    }
}
