#pragma once
#include "Map.h"
class door : public Map
{
public:
    door(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);sprite.setScale(0.1,0.1);};
    void update(float deltaTime, sf::Event* event) override;
    void draw(sf::RenderWindow* window) override;
    void interact(Player& player) override;
};
