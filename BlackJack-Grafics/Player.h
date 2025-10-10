#pragma once

#include <SFML/Graphics.hpp>

#include "BasePlayer.h"

class Player : public BasePlayer
{
public:
	Player(const string& name = "");
	virtual ~Player();

	virtual bool IsHitting(sf::RenderWindow &window, sf::Cursor &cursor) const;

	void Win(sf::RenderWindow& window) const;
	void Lose(sf::RenderWindow& window) const;
	void Draw(sf::RenderWindow& window) const;
};