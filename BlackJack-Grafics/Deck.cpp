#include <algorithm>

#include "Deck.h"

Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}
Deck::~Deck()
{
}

void Deck::Populate()
{
	Clear();

	for (int s = Card::CLUBS; s <= Card::SPADES; s++)
	{
		for (int r = Card::ACE; r <= Card::KING; r++)
		{
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!(m_Cards.empty()))
	{
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
}
void Deck::AdditionalCards(BasePlayer& aBasePlayer)
{
	cout << endl;

	while (!(aBasePlayer.IsBusted()) && aBasePlayer.IsHitting())
	{
		Deal(aBasePlayer);
		// cout << aBasePlayer << endl;

		if (aBasePlayer.IsBusted())
		{
			aBasePlayer.Bust();
		}
	}
}