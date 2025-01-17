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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && endurance >= 0)
    {
        speed = 10;
        endurance -= 1;
    }
    if (event->KeyReleased && event->key.code == sf::Keyboard::LShift)
    {
        std::cout << speed << std::endl;
        speed = 5;
    }
    if (endurance <= 0)
    {
        speed = 5;
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && endurance <= 100)
    {
        endurance += 1;
    }
}

void Player::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}

