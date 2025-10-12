#pragma once

#include "BasePlayer.h"

class House : public BasePlayer
{
public:
	House(const string& name = "House");
	virtual ~House();

	virtual bool IsHitting(sf::RenderWindow& window, sf::Cursor& cursor) const;

	void FlipFirstCard();
};