#include <SFML/Graphics.hpp>
#include "Entity.h"


class Player : public Entity
{
private:
    int life = 5;
    int maxLife = 5;
public:
    bool iswinning = false;
    int speed = 5;
    int key = 0;
    Player(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);sprite.setScale(0.1,0.1);};
    void update(float deltaTime,sf::Event* event) override;
    void draw(sf::RenderWindow* window) override;
    ~Player(){};
};