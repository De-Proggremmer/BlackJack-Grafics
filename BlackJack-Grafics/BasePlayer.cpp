#include "BasePlayer.h"

BasePlayer::BasePlayer(const string& name) : m_Name(name)
{
}
BasePlayer::~BasePlayer()
{
}

bool BasePlayer::IsBusted() const
{
	return (GetTotal() > 21);
}

string BasePlayer::Bust() const
{
	return m_Name + " busts";
}

//ostream& operator<<(ostream& os, const BasePlayer& aBasePlayer)
//{
//	os << aBasePlayer.m_Name << ":\t";
//
//	vector<Card*>::const_iterator pCard;
//
//	if (!aBasePlayer.m_Cards.empty())
//	{
//		for (pCard = aBasePlayer.m_Cards.begin(); pCard != aBasePlayer.m_Cards.end(); pCard++)
//		{
//			os << *(*pCard) << "\t";
//		}
//
//		if (aBasePlayer.GetTotal() != 0)
//		{
//			cout << "(" << aBasePlayer.GetTotal() << ")";
//		}
//	}
//	else
//	{
//		os << "<empty>";
//	}
//
//	return os;
//}