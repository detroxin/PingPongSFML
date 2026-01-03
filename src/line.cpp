#include "line.h"


Line::Line() {
    
}

void Line::generate(float screenWidth, float screenHeight, float thickness, float dashSpacing) {
    const int dashCount = 8;

    const float dashHeight = (screenHeight - dashSpacing * (dashCount + 1)) / dashCount;

    for(int i = 0; i < screenHeight / dashCount; i++) {
        sf::RectangleShape shape(sf::Vector2f(thickness, dashHeight));

        float startY = dashSpacing + ((dashHeight + dashSpacing) * i);

        shape.setPosition({screenWidth / 2 - thickness / 2, startY});
        this->dashes.push_back(shape);
    }
}

void Line::render(sf::RenderWindow *window, int screenWidth, int screenHeight) {
    for(auto& shape : this->dashes) {
        window->draw(shape);
    }
}