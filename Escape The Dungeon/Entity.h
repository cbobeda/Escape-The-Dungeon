#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
    sf::Sprite sprite;
    Entity(){};
    virtual void update(float deltaTime,sf::Event* event) =0;
    virtual void draw(sf::RenderWindow* window) = 0;
    ~Entity(){};
};