#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
//#include "joint.h"

//joint test = joint(1,0,0,2);

sf::RectangleShape rect;
sf::RectangleShape rectM;

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Physic");
    window.setFramerateLimit(60);
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition(sf::Vector2f(0, 800));
    rect.setSize(sf::Vector2f(10000000, 10));
    rectM.setFillColor(sf::Color::Blue);
    rectM.setPosition(sf::Vector2f(1300, 0));
    rectM.setSize(sf::Vector2f(10, 100000000000));
    sf::Event event;
    sf::Clock clock;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(rect);
        window.draw(rectM);
        //window.draw(test.update());
        window.display();
    }

    return 0;
}

