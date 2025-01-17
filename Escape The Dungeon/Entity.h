#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(){};
    virtual void update(float deltaTime,sf::Event* event) =0;
    virtual void draw(sf::RenderWindow* window) = 0;
    ~Entity(){};
};