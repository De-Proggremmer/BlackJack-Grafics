#include "Player.h"

Player::Player(const string& name) : BasePlayer(name)
{
}
Player::~Player()
{
}

bool Player::IsHitting(sf::RenderWindow &window, sf::Cursor& cursor) const
{
	sf::Font pixel_font;
	if (!(pixel_font.loadFromFile("Materials/Fonts/PixelFont.otf")))
	{
		cout << "font err!" << endl;
	}
	

	sf::Text question;
	question.setFont(pixel_font);
	question.setCharacterSize(30);
	question.setFillColor(sf::Color::Transparent);
	question.setPosition(810, 300);
	question.setString("Вы хотите еще одну карту?");


	sf::Texture y_button;
	if (!(y_button.loadFromFile("Materials/Buttons/Yes_button.png")))
	{
		cout << "y_b image err!" << endl;
	}
	sf::Texture n_button;
	if (!(n_button.loadFromFile("Materials/Buttons/No_button.png")))
	{
		cout << "n_b image err!" << endl;
	}


	sf::Sprite Y_botton;
	sf::Sprite N_botton;

	Y_botton.setTexture(y_button);
	Y_botton.setPosition(530, 450);
	N_botton.setTexture(n_button);
	N_botton.setPosition(1090, 450);

	window.clear(sf::Color::White);

	window.draw(question);
	window.draw(Y_botton);
	window.draw(N_botton);

	bool hitting;

	while (true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Получение позиции клика

					if (Y_botton.getGlobalBounds().contains(mousePos.x, mousePos.y))
					{
						hitting = true;
					}
					else if (N_botton.getGlobalBounds().contains(mousePos.x, mousePos.y))
					{
						hitting = false;
					}
				}
			}
		}

		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (Y_botton.getGlobalBounds().contains(mousePos.x, mousePos.y) || N_botton.getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			cursor.loadFromSystem(sf::Cursor::Hand);
			window.setMouseCursor(cursor);
		}
		else
		{
			cursor.loadFromSystem(sf::Cursor::Arrow);
			window.setMouseCursor(cursor);
		}
	}

	return hitting;
}

void Player::Win(sf::RenderWindow& window) const
{
	sf::Font pixel_font;
	if (!(pixel_font.loadFromFile("Materials/Fonts/PixelFont.otf")))
	{
		cout << "font err!" << endl;
	}

	sf::Text note;
	note.setFont(pixel_font);
	note.setCharacterSize(30);
	note.setFillColor(sf::Color::Transparent);
	note.setPosition(810, 780);
	note.setString("Кликните, чтобы продолжить");


	sf::Texture win_texture;
	if (!(win_texture.loadFromFile("Materials/Notes/Win.png")))
	{
		cout << "win image err!" << endl;
	}

	sf::Sprite win_note;

	win_note.setTexture(win_texture);
	win_note.setPosition(530, 450);


	window.clear(sf::Color::Black);

	window.draw(win_note);
	window.draw(note);

	while (true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					window.clear(sf::Color::White);
					break;
				}
			}
		}
	}
}

void Player::Lose(sf::RenderWindow& window) const
{
	sf::Font pixel_font;
	if (!(pixel_font.loadFromFile("Materials/Fonts/PixelFont.otf")))
	{
		cout << "font err!" << endl;
	}

	sf::Text note;
	note.setFont(pixel_font);
	note.setCharacterSize(30);
	note.setFillColor(sf::Color::Transparent);
	note.setPosition(810, 780);
	note.setString("Кликните, чтобы продолжить");


	sf::Texture win_texture;
	if (!(win_texture.loadFromFile("Materials/Notes/Lose.png")))
	{
		cout << "win image err!" << endl;
	}

	sf::Sprite win_note;

	win_note.setTexture(win_texture);
	win_note.setPosition(530, 450);


	window.clear(sf::Color::Black);

	window.draw(win_note);
	window.draw(note);

	while (true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					window.clear(sf::Color::White);
					break;
				}
			}
		}
	}
}

void Player::Draw(sf::RenderWindow& window) const
{
	sf::Font pixel_font;
	if (!(pixel_font.loadFromFile("Materials/Fonts/PixelFont.otf")))
	{
		cout << "font err!" << endl;
	}

	sf::Text note;
	note.setFont(pixel_font);
	note.setCharacterSize(30);
	note.setFillColor(sf::Color::Transparent);
	note.setPosition(810, 780);
	note.setString("Кликните, чтобы продолжить");


	sf::Texture win_texture;
	if (!(win_texture.loadFromFile("Materials/Notes/Draw.png")))
	{
		cout << "win image err!" << endl;
	}

	sf::Sprite win_note;

	win_note.setTexture(win_texture);
	win_note.setPosition(530, 450);


	window.clear(sf::Color::Black);

	window.draw(win_note);
	window.draw(note);

	while (true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					window.clear(sf::Color::White);
					break;
				}
			}
		}
	}
}
