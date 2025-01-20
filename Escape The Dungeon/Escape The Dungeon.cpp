#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "ChaseEnnemy.h"
#include "PatrolEnnemy.h"
#include <vector>

bool isDead = false;

Player p(50,50,"pp.png");
std::vector<Ennemy*> ennemies;


int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Escape The Dungeon");
    sf::Event event;
    sf::Clock clock;
    ennemies.push_back(new ChaseEnnemy(50,50,"pp.png"));
    ennemies.push_back(new PatrolEnnemy(300,300,"pp.png"));
    while (window.isOpen())
    {
        if (!isDead)
        {
            p.update(1, &event);
            for (auto& ennemy : ennemies)
            {
                ennemy->update(1,&event);
            }
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            
            }
            for (auto& ennemy : ennemies)
            {
                if (p.sprite.getGlobalBounds().intersects(ennemy->sprite.getGlobalBounds()))
                {
                    isDead = true;
                }
            }
            window.clear();
            p.draw(&window);
            for (auto& ennemy : ennemies)
            {
                ennemy->draw(&window);
            }
        }
        else
        {
            window.clear();
            for (auto& ennemy : ennemies)
            {
                ennemy->draw(&window);
            }
            isDead = false;
        }
        window.display();
    }
    for (auto& ennemy : ennemies)
    {
        delete ennemy;
    }

    return 0;
}

