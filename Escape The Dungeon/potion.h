#pragma once
#include "Object.h"

class Potion : public Object
{
public:
    Potion(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);sprite.setScale(0.1,0.1);};
    void interact(Player& player) override;
    void draw(sf::RenderWindow* window) override;
    void update(float deltaTime, sf::Event* event) override;
};
