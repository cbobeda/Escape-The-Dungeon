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
#include "Wall.h"
#include "Sol.h"
#include "Nourriture.h"
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
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Escape The Dungeon", sf::Style::Fullscreen);
    sf::Event event;
    sf::Clock clock;
    sf::Font font;
    font.loadFromFile("POWER_UP.otf");
    sf::Texture texture;
    texture.loadFromFile("Loading.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    window.draw(sprite);
    sf::Text text;
    text.setFont(font);
    text.setString("Place holder");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(5);
    text.setOrigin(text.getLocalBounds().width / 2.0f,text.getLocalBounds().height / 2.0f);
    text.setPosition(window.getSize().x / 2.0f, 30);
    text.setScale(1.5, 1.5);
    std::ifstream fichier("map.txt", std::ios::in);
    while (std::getline(fichier, line)) {
        std::cout << line << std::endl;

        for (int x = 0; x < line.size(); x++)
        {
            if (line[x] == ' ')
            {
                maps.push_back(new Sol(x * 40, i * 40, "Sol.png"));
            }
            else if (line[x] == '#')
            {
                maps.push_back(new Wall(x * 40, i * 40, "wall.png"));
            }
            else if (line[x] == '.')
            {
                maps.push_back(new Sol(x * 40, i * 40, "Sol.png"));
                maps.push_back(new door(x * 40, i * 40, "Door.png"));
            }
            else if (line[x] == 'P')
            {
                maps.push_back(new Sol(x * 40, i * 40, "Sol.png"));
                objects.push_back(new Potion(x * 40,i * 40,"speedpot.png"));
            }
            else if (line[x] == 'K')
            {
                maps.push_back(new Sol(x * 40, i * 40, "Sol.png"));
                objects.push_back(new Key(x * 40,i * 40,"cle.png"));
            }
            else if (line[x] == 'S')
            {
                maps.push_back(new Sol(x * 40, i * 40, "Sol.png"));
                objects.push_back(new Nourriture(x * 40, i * 40, "meat.png"));
            }
            else if (line[x] == 'C')
            {
                maps.push_back(new Sol(x * 40, i * 40, "Sol.png"));
                ennemies.push_back(new ChaseEnnemy(x * 40,i * 40,"follow.png"));
            }
            else if (line[x] == 'G')
            {
                maps.push_back(new Sol(x * 40, i * 40, "Sol.png"));
                ennemies.push_back(new PatrolEnnemy(x * 40,i * 40,"patrol.png"));
            }
            else if (line[x] == 'J')
            {
                maps.push_back(new Sol(x * 40, i * 40, "Sol.png"));
                p.sprite.setPosition(x * 40,i * 40);
            }
        }

        i++;
    }
    
    while (window.isOpen())
    {
        if (!isDead && !p.iswinning)
        {
            if (60 - clock.getElapsedTime().asSeconds() <= 0)
            {
                isDead = true;
            }
            p.update(1, &event);
            for (auto& ennemy : ennemies)
            {
                ennemy->update(1,&event);
            }
            std::vector<Object*> toDelete;
            std::vector<Map*> toDeleteMap;

            for (auto& obj : objects)
            {
                if (obj->shouldBeDeleted)
                    toDelete.push_back(obj);
            }
            for (auto& doors : maps)
            {
                if (doors->shouldBeDeleted)
                    toDeleteMap.push_back(doors);
            }
            for (auto* obj : toDelete)
            {
                objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
                delete obj;
            }
            for (auto* doors : toDeleteMap)
            {
                maps.erase(std::remove(maps.begin(), maps.end(), doors), maps.end());
                delete doors;
            }
            for (auto& obj : objects)
            {
                obj->interact(p);
            }
            for (auto& tiles : maps)
            {
                tiles->interact(p, &event);
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
            for (auto& tile : maps)
            {
                tile->draw(&window);
            }
            p.draw(&window);
            for (auto& ennemy : ennemies)
            {
                ennemy->draw(&window);
            }
            for (auto& obj : objects)
            {
                obj->draw(&window);
            }
            text.setString(std::to_string(60-(int)clock.getElapsedTime().asSeconds()));
            window.draw(text);
            
        }
        else if (isDead)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            
            }
            window.clear();
            window.draw(sprite);
            text.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
            text.setString("Game Over");
            window.draw(text);
        }
        else if (p.iswinning)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            
            }
            window.clear();
            window.draw(sprite);
            text.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
            text.setString("You Win!");
            window.draw(text);
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
    for (auto& tiles : maps)
    {
        delete tiles;
    }
    return 0;
}

