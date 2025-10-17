#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Black Jack"); // sf::Style::Fullscreen
    sf::RenderWindow& p_window = window;

    sf::Texture exit_button_texture;
    if (!exit_button_texture.loadFromFile("Materials/Buttons/Exit_button.png"))
    {
        return -1;
    }

    sf::Sprite exit_button_sprite;
    exit_button_sprite.setTexture(exit_button_texture);
    exit_button_sprite.setPosition(1848, 0);

    sf::Cursor cursor;
    sf::Cursor &p_cursor = cursor;

    std::vector<std::string> names = { "Илья" };

    Game game = Game(names);

    game.Draw(p_window, p_cursor, exit_button_sprite);

    return 0;
}