#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(){};
    virtual void update(float deltaTime) =0;
    virtual void draw(sf::RenderWindow* window) = 0;
    ~Entity(){};
};