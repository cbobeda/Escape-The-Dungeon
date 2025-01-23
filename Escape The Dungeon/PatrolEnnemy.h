#pragma once
#include "Ennemy.h"

class PatrolEnnemy : public Ennemy
{
private:
    float Posx;
    float Posy;
    int speed = 1;
    int life = 5;
    int maxLife = 5;
    int i = 0;
    sf::Vector2f position[4] = {{Posx,Posy},{Posx + 200,Posy},{Posx + 200,Posy + 200},{Posx,Posy + 200}};
public:
    PatrolEnnemy(int x, int y, sf::String chemin):Posx(x),Posy(y){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(Posx, Posy);sprite.setScale(0.1,0.1);};
    void update(float deltaTime,sf::Event* event) override;
    void draw(sf::RenderWindow* window) override;
    ~PatrolEnnemy(){};
};