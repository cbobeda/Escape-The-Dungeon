#include "Wall.h"
#include <iostream>
void Wall::update(float deltaTime, sf::Event* event)
{
    
}

void Wall::interact(Player& player, sf::Event* event)
{
    // Vérifier si le joueur entre en collision avec la porte
    if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.sprite.move(-player.speed,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            player.sprite.move(player.speed,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            player.sprite.move(0,player.speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            player.sprite.move(0,-player.speed);
        }
    }

    
}


void Wall::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
