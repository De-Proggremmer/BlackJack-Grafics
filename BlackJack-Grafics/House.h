#pragma once

#include "BasePlayer.h"

class House : public BasePlayer
{
public:
	House(const string& name = "House");
	virtual ~House();

	virtual bool IsHitting() const;

	void FlipFirstCard();
};