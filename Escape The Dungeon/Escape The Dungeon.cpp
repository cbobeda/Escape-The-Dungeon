#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "ChaseEnnemy.h"

Player p(50,50,"pp.png");
ChaseEnnemy chaseEnnemy(50,50,"pp.png");

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Escape The Dungeon");
    sf::Event event;
    sf::Clock clock;
    while (window.isOpen())
    {
        p.update(1, &event);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        p.draw(&window);
        chaseEnnemy.draw(&window);
        window.display();
    }

    return 0;
}

