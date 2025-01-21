#pragma once
#include "Entity.h"
#include "Player.h"

class Object : public Entity
{
public:
    virtual void interact(Player& player) = 0;
    virtual void draw(sf::RenderWindow* window) = 0;
};
