#ifndef STATE_H
#define STATE_H

class Miner;

class State
{
public:

	virtual void Enter(Miner*) = 0;

	virtual void Execute(Miner*) = 0;

	virtual void Exit(Miner*) = 0;

	virtual ~State(){}
};
#endif


