#include "PatrolEnnemy.h"
#include <iostream>
#include <cmath> // Pour std::abs

sf::Clock clo;
void PatrolEnnemy::update(float deltaTime, sf::Event* event)
{
    if (sprite.getColor().a == 50 && clo.getElapsedTime().asSeconds() > 0.5)
    {
        sprite.setColor(sf::Color(255,255,255,255));
        clo.restart();
    }
    else if (clo.getElapsedTime().asSeconds() > 0.5)
    {
        sprite.setColor(sf::Color(255,255,255,50));
        clo.restart();
    }
    if (i >= 4) {
        std::cerr << "Erreur : Indice 'i' dépasse la taille de 'position'.\n";
        i = 0;
        return;
    }

    
    if (std::abs(sprite.getPosition().x - position[i].x) > 0.1f) {
        float dirX = (position[i].x > sprite.getPosition().x) ? 1.0f : -1.0f;
        sprite.move(dirX * speed * deltaTime, 0);
    }

    
    if (std::abs(sprite.getPosition().y - position[i].y) > 0.1f) {
        float dirY = (position[i].y > sprite.getPosition().y) ? 1.0f : -1.0f;
        sprite.move(0, dirY * speed * deltaTime);
    }

    
    if (std::abs(sprite.getPosition().x - position[i].x) <= 0.1f &&
        std::abs(sprite.getPosition().y - position[i].y) <= 0.1f) {
        i++;
        if (i >= 4) {
            i = 0; 
        }
        }
}

void PatrolEnnemy::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}