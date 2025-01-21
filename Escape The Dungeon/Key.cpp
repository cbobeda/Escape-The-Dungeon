#include "Key.h"

#include <iostream>

void Key::interact(Player& player)
{
    if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
    {
        std::cout << "key interact" << std::endl;
        player.key += 1;
        shouldBeDeleted = true;
    }
}

void Key::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
void Key::update(float deltaTime, sf::Event* event)
{
    
}