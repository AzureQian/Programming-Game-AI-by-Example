#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H

#include "State.h"

class Miner;

class EnterMinerAndDigForNugget : public State<Miner>
{
private:

	EnterMinerAndDigForNugget() {}

	EnterMinerAndDigForNugget(const EnterMinerAndDigForNugget&);
	EnterMinerAndDigForNugget& operator= (const EnterMinerAndDigForNugget&);

public:

	static EnterMinerAndDigForNugget* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
};

class VisitBankAndDepositGold : public State<Miner>
{
private:

	VisitBankAndDepositGold() {}

	VisitBankAndDepositGold(const VisitBankAndDepositGold&);
	VisitBankAndDepositGold& operator= (const VisitBankAndDepositGold&);

public:

	static VisitBankAndDepositGold* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
};

class GoHomeAndSleepTilRestored : public State<Miner>
{
private:

	GoHomeAndSleepTilRestored() {}

	GoHomeAndSleepTilRestored(const GoHomeAndSleepTilRestored&);
	GoHomeAndSleepTilRestored& operator= (const GoHomeAndSleepTilRestored&);

public:

	static GoHomeAndSleepTilRestored* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
};

class QuenchThirst : public State<Miner>
{
private:

	QuenchThirst() {}

	QuenchThirst(const QuenchThirst&);
	QuenchThirst& operator= (const QuenchThirst&);

public:

	static QuenchThirst* Instance();

	virtual void Enter(Miner* miner);
	virtual void Execute(Miner* miner);
	virtual void Exit(Miner* miner);
};

#endif
