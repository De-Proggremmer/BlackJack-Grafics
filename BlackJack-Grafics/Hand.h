#pragma once

#include <vector>

#include "Card.h"

class Hand
{
public:
	Hand();
	virtual ~Hand();

	void Add(Card* pCard);
	void Clear();

	int GetTotal() const;

protected:
	vector<Card*> m_Cards;
};