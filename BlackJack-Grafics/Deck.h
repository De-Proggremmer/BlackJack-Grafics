#pragma once

#include "Hand.h"
#include "BasePlayer.h"

class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck();

	void Populate();

	void Shuffle();

	void Deal(Hand& aHand);
	void AdditionalCards(BasePlayer& aBasePlayer);
};