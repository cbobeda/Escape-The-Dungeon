#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>

#include "Object.h"

class Key : public Object
{
public:
    Key(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);sprite.setScale(0.1,0.1);};
    void interact(Player& player) override;
    void draw(sf::RenderWindow* window) override;
    void update(float deltaTime, sf::Event* event) override;
};
