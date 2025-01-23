#include "Player.h"

#include <iostream>

void Player::update(float deltaTime, sf::Event* event)
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canMoveRight)
    {
        sprite.move(speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && canMoveLeft)
    {
        sprite.move( -speed , 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && canMoveUp)
    {
        sprite.move( 0 , -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canMoveDown)
    {
        sprite.move(  0, speed);
    }
}

void Player::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}

