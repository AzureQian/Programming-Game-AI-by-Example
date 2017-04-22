#ifndef MINER_H
#define MINER_H

#include <string>
#include <cassert>
#include "BaseGameEntity.h"
#include "Locations.h"

class State;

const int ComfortLevel = 5;
const int MaxNuggets = 3;
const int ThirstLevel = 5;
const int TirednessThreshold = 5;

class Miner : public BaseGameEntity
{
private:
	State*			m_pCurrentState;
	
	location_type	m_Location;

	int				m_iGoldCarried;
	int				m_iMoneyInBank;
	int				m_iThirst;
	int				m_iFatigue;

public:
	Miner(int id);

	void Update();

	void ChanegState(State* new_state);

	location_type	Location() const { return m_Location; }


	void			ChangeLocation(const location_type loc) { m_Location = loc; }

	int				GoldCarried() const { return m_iGoldCarried; }
	void			SetGoldCarried(const int val) { m_iGoldCarried = val; }
	void			AddToGoldCarried(const int val);
	bool			PocketsFull() const { return m_iGoldCarried >= MaxNuggets; }

	bool			Fatigued() const;
	void			DecreaseFatigue() { m_iFatigue -= 1; }
	void			IncreaseFatigue() { m_iFatigue += 1; }

	int				Wealth() const { return m_iMoneyInBank; }
	void			SetWealth(const int val) { m_iMoneyInBank = val; }
	void			AddToWealth(const int val);

	bool			Thirsty() const;
	void			BuyAndDrinkWhiskey() { m_iThirst = 0; m_iMoneyInBank -= 2; }
};

#endif
