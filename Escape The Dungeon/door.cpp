#include "door.h"
#include <iostream>
void door::update(float deltaTime, sf::Event* event)
{
    
}

void door::interact(Player& player)
{
    
    if (sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
    {
        if (player.key > 0)
        {
            std::cout << "door interact" << std::endl;
            player.key -= 1;
            shouldBeDeleted = true;
        }
    }
    else
    {
        player.canMoveLeft = true;
        player.canMoveRight = true;
        sf::FloatRect playerBounds = player.sprite.getGlobalBounds();
        sf::FloatRect objectBounds = sprite.getGlobalBounds();

        // Vérifier la collision à gauche
        if (objectBounds.left < playerBounds.left && objectBounds.left + objectBounds.width > playerBounds.left) {
            std::cout << "Collision à gauche avec un objet !" << std::endl << objectBounds.width << "      " << objectBounds.left << "   " << playerBounds.left << std::endl;
            player.canMoveLeft = false;
        }

        // Vérifier la collision à droite
        if (objectBounds.left > playerBounds.left && objectBounds.left < playerBounds.left + playerBounds.width) {
            std::cout << "Collision à droite avec un objet !" << std::endl;
            player.canMoveRight = false;
        }
    }
}

void door::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
