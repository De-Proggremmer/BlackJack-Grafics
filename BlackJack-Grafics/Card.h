#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Card
{
public:
	enum rank { TWO = 0, THEE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
	enum suit { CLUBS = 0, SPADES, HEARTS, DIAMONDS }; // Крести, Вини, Черви, Буби

	// friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r, suit s, sf::Texture m_CardFaceSprite, sf::Texture m_CoverSprite, bool ifu = true);

	int GetValue() const;

	sf::Texture& GetTexture() const;

	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;

	sf::Texture& m_CardSprite;

	sf::Texture m_CardFaceSprite;
	sf::Texture m_CoverSprite;
};