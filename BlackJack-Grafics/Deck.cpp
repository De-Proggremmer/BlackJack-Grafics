#include <algorithm>
#include <vector>

#include "Deck.h"

Deck::Deck()
{
	for (int i = 1; i <= 54; i++)
	{
		sf::Texture card_texture;
		card_texture.loadFromFile("Materials/Cards/" + std::to_string(i) + ".jpg");
		m_cards.push_back(card_texture);
	}

	Populate();
}
Deck::~Deck()
{
}

void Deck::Populate()
{
	Clear();

	for (int s = Card::CLUBS; s <= Card::DIAMONDS; s++)
	{
		for (int r = Card::TWO; r <= Card::ACE; r++)
		{
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s), m_cards[0], m_cards[0]));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

Card* Deck::Deal(Hand& aHand)
{
	if (!(m_Cards.empty()))
	{
		Card *card = m_Cards.back();
		aHand.Add(card);
		m_Cards.pop_back();
		return card;
	}
}
void Deck::AdditionalCards(BasePlayer& aBasePlayer, sf::RenderWindow& window, sf::Cursor& cursor)
{
	while (!(aBasePlayer.IsBusted()) && aBasePlayer.IsHitting(window, cursor))
	{
		Deal(aBasePlayer);

		if (aBasePlayer.IsBusted())
		{
			aBasePlayer.Bust();
		}
	}
}