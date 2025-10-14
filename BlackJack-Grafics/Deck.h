#pragma once

#include "Hand.h"
#include "BasePlayer.h"

class Deck : public Hand
{
public:
	Deck(vector<sf::Sprite> face);
	virtual ~Deck();

	void Populate();

	void Shuffle();

	Card Deal(Hand& aHand);
	void AdditionalCards(BasePlayer& aBasePlayer, sf::RenderWindow& window, sf::Cursor& cursor);
private:
	vector<sf::Sprite> m_cards;
};