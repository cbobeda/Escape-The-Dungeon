#pragma once
#include <SFML/Graphics.hpp>


class Entity
{
public:
    sf::Sprite sprite;
    sf::Texture texture;
    bool shouldBeDeleted = false;
    Entity(){};
    virtual void update(float deltaTime,sf::Event* event) =0;
    virtual void draw(sf::RenderWindow* window) = 0;
    ~Entity(){};
};