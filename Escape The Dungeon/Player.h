#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int speed = 5;
    int life = 5;
    int maxLife = 5;
    float endurance = 100;
    float maxEndurance = 100;
public:
    
    Player(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);sprite.setScale(0.1,0.1);};
    void update(float deltaTime,sf::Event* event) override;
    void draw(sf::RenderWindow* window) override;
    ~Player(){};
};