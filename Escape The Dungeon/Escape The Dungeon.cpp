#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Escape The Dungeon");
    window.setFramerateLimit(60);
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
        window.display();
    }

    return 0;
}

