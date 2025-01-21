#include "potion.h"

#include <iostream>

void Potion::interact(Player& player)
{
    if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
    {
        std::cout << "potion interact" << std::endl;
        player.speed *= 1.2;
        shouldBeDeleted = true;
    }
}

void Potion::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
void Potion::update(float deltaTime, sf::Event* event)
{
    
}