#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Card
{
public:
	enum rank { TWO = 1, THEE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
	enum suit { CLUBS = 1, SPADES, HEARTS, DIAMONDS }; // Крести, Вини, Черви, Буби

	// friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r = ACE, suit s = SPADES, bool ifu = true, sf::Sprite *m_CardFaceSprite, sf::Sprite *m_CoverSprite);

	int GetValue() const;

	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;

	sf::Sprite m_CardSprite;

	sf::Sprite *m_CardFaceSprite;
	sf::Sprite *m_CoverSprite;
};