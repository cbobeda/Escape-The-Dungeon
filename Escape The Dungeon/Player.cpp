#include "Player.h"

#include <iostream>

void Player::update(float deltaTime, sf::Event* event)
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        sprite.move( -speed , 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        sprite.move( 0 , -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(  0, speed);
    }
}

void Player::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}

