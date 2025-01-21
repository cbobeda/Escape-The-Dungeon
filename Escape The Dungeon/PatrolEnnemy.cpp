#include "PatrolEnnemy.h"
#include <iostream>
#include <cmath> // Pour std::abs
void PatrolEnnemy::update(float deltaTime, sf::Event* event)
{
    // Vérifier que l'indice i est valide
    if (i >= 4) {
        std::cerr << "Erreur : Indice 'i' dépasse la taille de 'position'.\n";
        i = 0;
        return;
    }

    // Déplacement horizontal
    if (std::abs(sprite.getPosition().x - position[i].x) > 0.1f) {
        float dirX = (position[i].x > sprite.getPosition().x) ? 1.0f : -1.0f;
        sprite.move(dirX * speed * deltaTime, 0);
    }

    // Déplacement vertical
    if (std::abs(sprite.getPosition().y - position[i].y) > 0.1f) {
        float dirY = (position[i].y > sprite.getPosition().y) ? 1.0f : -1.0f;
        sprite.move(0, dirY * speed * deltaTime);
    }

    // Vérifier si l'ennemi a atteint la position cible
    if (std::abs(sprite.getPosition().x - position[i].x) <= 0.1f &&
        std::abs(sprite.getPosition().y - position[i].y) <= 0.1f) {
        i++;
        if (i >= 4) {
            i = 0; // Boucle sur le chemin
        }
        }
}

void PatrolEnnemy::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}