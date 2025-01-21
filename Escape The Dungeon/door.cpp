#include "door.h"
#include <iostream>
void door::update(float deltaTime, sf::Event* event)
{
    
}

void door::interact(Player& player)
{
    if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
    {
        std::cout << "door interact" << std::endl;
        shouldBeDeleted = true;
    }
}

void door::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
