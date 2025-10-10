#pragma once

#include <iostream>
#include <string>

#include "Hand.h"

using namespace std;

class BasePlayer : public Hand
{
	// friend ostream& operator<<(ostream& os, const BasePlayer& aBasePlayer);

public:
	BasePlayer(const string& name = "");
	virtual ~BasePlayer();

	virtual bool IsHitting() const = 0;
	bool IsBusted() const;
	string Bust() const;

protected:
	string m_Name;
};