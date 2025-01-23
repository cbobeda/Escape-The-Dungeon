#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "ChaseEnnemy.h"
#include "PatrolEnnemy.h"
#include "potion.h"
#include "Key.h"
#include "door.h"
#include <vector>


bool isDead = false;
std::string line;
int i;

Player p(800,800,"pp.png");
std::vector<Ennemy*> ennemies;
std::vector<Object*> objects;
std::vector<Map*> maps;


int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Escape The Dungeon");
    sf::Event event;
    sf::Clock clock;
    std::ifstream fichier("map.txt", std::ios::in);
    door d = door(500,500,"pp.png");
    ennemies.push_back(new ChaseEnnemy(50,50,"follow.png"));
    ennemies.push_back(new PatrolEnnemy(300,300,"patrol.png"));
    getline(fichier,line);
    std::cout << line << std::endl;
    for (auto character : line)
    {
        if (character == '#')
        {
            maps.push_back(new door(i * 40,0,"pp.png"));
            i++;
        }
    }
    for (unsigned int i = 0; i < 10; i++)
    {
        if (rand() % 2 == 0)
        {
            objects.push_back(new Potion(rand()%1000,rand()%1000,"speedpot.png"));
        }
        else
        {
            objects.push_back(new Key(rand()%1000,rand()%1000,"cle.png"));
        }
    }
    while (window.isOpen())
    {
        if (!isDead)
        {
            p.update(1, &event);
            for (auto& ennemy : ennemies)
            {
                ennemy->update(1,&event);
            }
            std::vector<Object*> toDelete;

            for (auto& obj : objects)
            {
                if (obj->shouldBeDeleted)
                    toDelete.push_back(obj);
            }
            for (auto* obj : toDelete)
            {
                objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
                delete obj;
            }
            for (auto& obj : objects)
            {
                obj->interact(p);
            }

            d.interact(p);
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            
            }
            for (auto& ennemy : ennemies)
            {
                if (p.sprite.getGlobalBounds().intersects(ennemy->sprite.getGlobalBounds()))
                {
                    window.close();
                }
            }
            window.clear();
            p.draw(&window);
            for (auto& ennemy : ennemies)
            {
                ennemy->draw(&window);
            }
            for (auto& obj : objects)
            {
                obj->draw(&window);
            }
            for (auto& tile : maps)
            {
                tile->draw(&window);
            }
        }
        else
        {
            window.clear();
            for (auto& ennemy : ennemies)
            {
                ennemy->draw(&window);
            }
            for (auto& obj : objects)
            {
                obj->draw(&window);
            }
            isDead = false;
        }
        window.display();
    }
    for (auto& ennemy : ennemies)
    {
        delete ennemy;
    }
    for (auto& obj : objects)
    {
        delete obj;
    }

    return 0;
}

