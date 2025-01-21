#pragma once
#include "Ennemy.h"

class PatrolEnnemy : public Ennemy
{
private:
    int speed = 1;
    int life = 5;
    int maxLife = 5;
    int i = 0;
    sf::Vector2f position[4] = {{40,40},{200,40},{200,200},{40,200}};
public:
    PatrolEnnemy(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);sprite.setScale(0.1,0.1);};
    void update(float deltaTime,sf::Event* event) override;
    void draw(sf::RenderWindow* window) override;
    ~PatrolEnnemy(){};
};