#include "Game.h"

#include <vector>

Game::Game(const vector<string> names, vector<sf::Sprite> cards): m_Deck(cards)
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

void Game::Play(sf::RenderWindow& window, sf::Cursor& cursor, sf::Sprite ex_b)
{
	vector<Player>::iterator pPlayer;

	House& p_House = m_House;

	vector<sf::Sprite> Player_cards;
	vector<sf::Sprite> House_cards;

	for (int i = 0; i < 2; i++)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
		{
			Player_cards.push_back(m_Deck.Deal(*pPlayer).GetSprite());
		}

		House_cards.push_back(m_Deck.Deal(m_House).GetSprite());
	}

	m_House.FlipFirstCard();

	while (window.isOpen())
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
		{
			m_Deck.AdditionalCards(*pPlayer, window, cursor);
		}

		m_House.FlipFirstCard();

		m_Deck.AdditionalCards(p_House, window, cursor);

		if (m_House.IsBusted())
		{
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
			{
				if (!(pPlayer->IsBusted()))
				{
					pPlayer->Win(window);
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
			}
		}


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
						for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); pPlayer++)
						{
							pPlayer->Clear();
						}
						m_House.Clear();
						window.close();
					}
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

		for (vector<sf::Sprite>::iterator i = House_cards.begin(); i != House_cards.end(); i++)
		{
			window.draw(*i);
		}

		for (vector<sf::Sprite>::iterator i = Player_cards.begin(); i != Player_cards.end(); i++)
		{
			window.draw(*i);
		}

		window.draw(ex_b);

		window.display();
	}
}