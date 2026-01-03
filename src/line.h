#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Line {
    private:
        std::vector<sf::RectangleShape> dashes;
    public:
        Line();
        void generate(float screenWidth, float screenHeight, float thickness, float dashSpacing);
        void render(sf::RenderWindow *window, int screenWidth, int screenHeight);
};