#include <SFML/Graphics.hpp>
#include "Ennemy.h"

class ChaseEnnemy : public Ennemy
{
    private:
    sf::Texture texture;
    sf::Sprite sprite;
    int speed = 5;
    int life = 5;
    int maxLife = 5;
public:
    ChaseEnnemy(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);sprite.setScale(0.1,0.1);};
    void update(float deltaTime,sf::Event* event) override;
    void draw(sf::RenderWindow* window) override;
    ~ChaseEnnemy(){};
};
