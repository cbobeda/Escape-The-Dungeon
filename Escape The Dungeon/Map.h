#pragma once
#include "Object.h"
#include "Entity.h"

class Map : public Entity
{
public:
    bool isFloor = false;
    void update(float deltaTime,sf::Event* event) override;
    void draw(sf::RenderWindow* window) override;
    virtual void interact(Player& player,sf::Event* event) = 0;
};
