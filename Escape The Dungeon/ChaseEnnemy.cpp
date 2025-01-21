#include "ChaseEnnemy.h"

#include "Player.h"


extern Player p;
void ChaseEnnemy::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}
sf::Vector2f normalize(const sf::Vector2f& vector)
{
    // Calcul de la norme
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    // Si la norme est proche de zéro, retourner un vecteur nul
    if (length == 0.0f)
        return sf::Vector2f(0.0f, 0.0f);

    // Diviser chaque composante par la norme
    return sf::Vector2f((vector.x / length), (vector.y / length));
}
void ChaseEnnemy::update(float deltaTime, sf::Event* event)
{
    sprite.move(normalize( p.sprite.getPosition() - sprite.getPosition()));
}