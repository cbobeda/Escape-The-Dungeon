#include "door.h"
#include <iostream>
void door::update(float deltaTime, sf::Event* event)
{
    
}

void door::interact(Player& player, sf::Event* event)
{
    // Vérifier si le joueur entre en collision avec la porte
    if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
    {
        // Vérifier si le joueur a une clé pour interagir avec la porte
        if (player.key > 0)
        {
            std::cout << "door interact" << std::endl;
            player.key -= 1;
            shouldBeDeleted = true; // Marquer la porte pour suppression
        }
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


void door::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
