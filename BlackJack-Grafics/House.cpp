#include "House.h"

#include <vector>

House::House(const string& name) : BasePlayer(name)
{
}
House::~House()
{
}

bool House::IsHitting(sf::RenderWindow& window, sf::Cursor& cursor) const
{
	return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
	if (!(m_Cards.empty()))
	{
		// m_Cards[0]->Flip();
	}
}

