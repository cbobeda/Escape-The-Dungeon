#include "Player.h"

void Player::update(float deltaTime)
{
    sf::Event event;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.move(0, 2);
    }
}

void Player::draw(sf::RenderWindow* window)
{
    window->draw(sprite);
}

