#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

// #include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Black Jack", sf::Style::Fullscreen);

    sf::Texture exit_button_texture;
    if (!exit_button_texture.loadFromFile("Materials/Buttons/Exit_button.png"))
    {
        return -1;
    }

    sf::Sprite exit_button_sprite;
    exit_button_sprite.setTexture(exit_button_texture);
    exit_button_sprite.setPosition(1848, 0);


    std::vector<sf::Texture> cards_t;
    std::vector<sf::Sprite> cards_s;
    for (int i = 1; i <= 54; i++)
    {
        sf::Texture card_texture;
        card_texture.loadFromFile("Materials/Cards/" + std::to_string(i) + ".jpg");
        cards_t.push_back(card_texture);
    }
    for (int i = 0; i < 54; i++)
    {
        sf::Sprite card_sprite;
        card_sprite.setTexture(cards_t[i]);
        card_sprite.setPosition(0, 0);
        cards_s.push_back(card_sprite);
    }

    sf::Cursor cursor;

    // vector<string> names = {"Илья"};

    //Game game = Game(names, cards_s);


    return 0;
}