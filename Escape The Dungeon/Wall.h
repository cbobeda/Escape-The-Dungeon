﻿#pragma once
#include "Map.h"

class Wall : public Map
{
public:
    int type = 1;
    Wall(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);sprite.setScale(0.1,0.1);};
    void update(float deltaTime, sf::Event* event) override;
    void draw(sf::RenderWindow* window) override;
    void interact(Player& player,sf::Event* event) override;
};
