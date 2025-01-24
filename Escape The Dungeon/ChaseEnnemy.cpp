#include "ChaseEnnemy.h"
#include "Map.h"

#include <cmath>
#include <vector>

extern Player p;
extern std::vector<Map*> maps;

sf::Clock cloc;

void ChaseEnnemy::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}

sf::Vector2f normalize(const sf::Vector2f& vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    
    if (length == 0.0f)
        return sf::Vector2f(0.0f, 0.0f);
    return sf::Vector2f(vector.x / length, vector.y / length);
}

void ChaseEnnemy::update(float deltaTime, sf::Event* event)
{
    if (sprite.getColor().a == 50 && cloc.getElapsedTime().asSeconds() > 0.5)
    {
        sprite.setColor(sf::Color(255,255,255,255));
        cloc.restart();
    }
    else if (cloc.getElapsedTime().asSeconds() > 0.5)
    {
        sprite.setColor(sf::Color(255,255,255,50));
        cloc.restart();
    }
    sf::Vector2f direction = normalize(p.sprite.getPosition() - sprite.getPosition());
    
    sf::Vector2f initialPosition = sprite.getPosition();
    
    sprite.move(normalize( p.sprite.getPosition() - sprite.getPosition()));
    
    for (auto& map : maps)
    {
        if (sprite.getGlobalBounds().intersects(map->sprite.getGlobalBounds()) && ! map->isFloor)
        {
            sprite.setPosition(initialPosition);
            break;
        }
    }
}
