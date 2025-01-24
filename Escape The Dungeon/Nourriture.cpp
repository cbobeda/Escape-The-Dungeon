#include "Nourriture.h"
#include <iostream>
void Nourriture::interact(Player& player)
{
    if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
    {
        std::cout << "Nourriture interact" << std::endl;
        player.speed *= 1.8;
        shouldBeDeleted = true;
    }
}

void Nourriture::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
void Nourriture::update(float deltaTime, sf::Event* event)
{
    
}