#pragma once

#include "BasePlayer.h"

class Player : public BasePlayer
{
public:
	Player(const string& name = "");
	virtual ~Player();

	virtual bool IsHitting() const;

	void Win() const;
	void Lose() const;
	void Push() const;
};