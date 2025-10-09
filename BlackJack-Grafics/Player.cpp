#include "Player.h"

Player::Player(const string& name) : BasePlayer(name)
{
}
Player::~Player()
{
}

bool Player::IsHitting() const
{
	cout << m_Name << ", do you want a hit?(y, n): ";
	char responce;
	cin >> responce;

	return (responce == 'y' || responce == 'Y');
}

void Player::Win() const
{
	cout << m_Name << " wins!" << endl;
}
void Player::Lose() const
{
	cout << m_Name << " loses!" << endl;
}
void Player::Push() const
{
	cout << m_Name << " pushes!" << endl;
}