#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int speed;
public:
    
    Player(int x, int y, sf::String chemin){texture.loadFromFile(chemin); sprite.setTexture(texture); sprite.setPosition(x, y);};
    void update(float deltaTime) override;
    void draw(sf::RenderWindow* window) override;
    ~Player(){};
};