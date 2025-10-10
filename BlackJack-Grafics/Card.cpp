#include "Card.h"

#include <SFML/Graphics.hpp>

using namespace std;

Card::Card(rank r, suit s, bool ifu, sf::Sprite *cardface_s, sf::Sprite *cover_s) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu), m_CardFaceSprite(cardface_s), m_CoverSprite(cover_s)
{
}

int Card::GetValue() const
{
	int value = 0;

	if (m_IsFaceUp)
	{
		value = m_Rank;

		if (value > 10)
		{
			if (value != 13)
			{
				value = 10;
			}
			else
			{
				value = 1;
			}
		}
	}

	return value;
}

void Card::Flip()
{
	if (m_IsFaceUp)
	{
		m_CardSprite = *m_CoverSprite;
	}
	else
	{
		m_CardSprite = *m_CardFaceSprite;
	}
	m_IsFaceUp = !(m_IsFaceUp);
}

//ostream& operator<<(ostream& os, const Card& aCard)
//{
//	const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
//	const string SUITS[] = { "c", "d", "h", "s" };
//
//	if (aCard.m_IsFaceUp)
//	{
//		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
//	}
//	else
//	{
//		os << "XX";
//	}
//
//	return os;
//}