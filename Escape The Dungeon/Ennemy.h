﻿#include "Entity.h"

class Ennemy : public Entity
{
private:

public:
    
    Ennemy(){};
    void update(float deltaTime,sf::Event* event) override;
    virtual void draw(sf::RenderWindow* window) override;
    ~Ennemy(){};
};