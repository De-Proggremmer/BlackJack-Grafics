#include "Game.h"

#include <vector>

Game::Game(const vector<string> names)
{
	vector<string>::const_iterator pName;

	for (pName = names.begin(); pName != names.end(); pName++)
	{
		m_Players.push_back(Player(*pName));
	}

	srand(static_cast<unsigned int>(time(0)));

	m_Deck.Populate();
	m_Deck.Shuffle();
}

Game::~Game()
{
}

void Game::Draw(sf::RenderWindow& window, sf::Cursor& cursor, sf::Sprite ex_b)
{
	bool flg = true;
	while (flg)
	{
		vector<Player>::iterator pPlayer;

		House& p_House = m_House;

		vector<sf::Texture> Player_cards;
		vector<sf::Texture> House_cards;

		for (int i = 0; i < 2; i++)
		{
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
			{
				sf::Sprite spr;
				sf::Texture texture = m_Deck.Deal(*pPlayer)->GetTexture();
				spr.setTexture(texture);
				//Player_cards.push_back(spr);
				cout << texture.getSize().x << "" << texture.getSize().y;
				window.clear(sf::Color::White);
				window.draw(spr);
				window.display();
				sf::sleep(sf::seconds(1));

			}

			House_cards.push_back(m_Deck.Deal(m_House)->GetTexture());
		}

		window.clear(sf::Color::White);

		/*for (vector<sf::Texture>::iterator i = House_cards.begin(); i != House_cards.end(); i++)
		{
			window.draw(*i);
		}

		for (vector<sf::Texture>::iterator i = Player_cards.begin(); i != Player_cards.end(); i++)
		{
			window.draw(*i);
		}*/

		window.display();


		sf::Font pixel_font;
		if (!(pixel_font.loadFromFile("Materials/Fonts/PixelFont.otf")))
		{
			cout << "font err!" << endl;
		}

		sf::sleep(sf::seconds(2));

		m_House.FlipFirstCard();

		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
		{
			m_Deck.AdditionalCards(*pPlayer, window, cursor);
		}

		m_House.FlipFirstCard();

		m_Deck.AdditionalCards(p_House, window, cursor);

		window.clear();

		if (m_House.IsBusted())
		{
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
			{
				if (!(pPlayer->IsBusted()))
				{
					pPlayer->Win(window);
				}
				else
				{
					pPlayer->Draw(window);
				}
			}
		}
		else
		{
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
			{
				if (!(pPlayer->IsBusted()))
				{
					if (pPlayer->GetTotal() > m_House.GetTotal())
					{
						pPlayer->Win(window);
					}
					else if (pPlayer->GetTotal() < m_House.GetTotal())
					{
						pPlayer->Lose(window);
					}
					else
					{
						pPlayer->Draw(window);
					}
				}
				else
				{
					pPlayer->Lose(window);
				}
			}
		}

		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
		{
			pPlayer->Clear();
		}
		m_House.Clear();

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

						if (ex_b.getGlobalBounds().contains(mousePos.x, mousePos.y))
						{
							flg = false;

							for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
							{
								pPlayer->Clear();
							}
							m_House.Clear();
							window.close();
						}
					}
					else if (event.Closed)
					{
						flg = false;

						for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
						{
							pPlayer->Clear();
						}
						m_House.Clear();
						window.close();
					}
				}
			}

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			if (ex_b.getGlobalBounds().contains(mousePos.x, mousePos.y))
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

			window.draw(ex_b);

			window.display();
		}
	}
}