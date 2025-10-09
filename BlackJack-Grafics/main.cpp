#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Black Jack", sf::Style::Fullscreen);

    sf::Texture exit_button_texture;
    if (!exit_button_texture.loadFromFile("Materials/Exit_button.png"))
    {
        return -1;
    }

    sf::Sprite exit_button_sprite;
    exit_button_sprite.setTexture(exit_button_texture);
    exit_button_sprite.setPosition(1848, 0);

    sf::Texture Card_t;
    if (!Card_t.loadFromFile("Materials/Cards/" + std::to_string(1) + ".jpg"))
    {
        return -1;
    }

    sf::Sprite Card_s;
    Card_s.setTexture(Card_t);
    Card_s.setPosition(0, 0);

    std::vector<sf::Texture> cards_t;
    std::vector<sf::Sprite> cards_s;
    for (int i = 1; i < 55; i++)
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

    int card_numb = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Получение позиции клика
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (exit_button_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        window.close();
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (card_numb + 1 == 54)
                    {
                        card_numb = 0;
                    }
                    else
                    {
                        card_numb++;
                    }
                }
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (exit_button_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
        {
            cursor.loadFromSystem(sf::Cursor::Hand);
            window.setMouseCursor(cursor);
        }
        else
        {
            cursor.loadFromSystem(sf::Cursor::Arrow);
            window.setMouseCursor(cursor);
        }

        window.clear(sf::Color::White);

        window.draw(exit_button_sprite);
        window.draw(cards_s[card_numb]);

        window.display();
    }

    return 0;
}