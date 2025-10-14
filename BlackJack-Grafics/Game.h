#pragma once

#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
public:
	Game(const vector<string> names, vector<sf::Sprite> cards);
	~Game();

	void Play(sf::RenderWindow& window, sf::Cursor& cursor, sf::Sprite ex_b);

private:
	Deck m_Deck;
	House m_House;

	vector<Player> m_Players;
};