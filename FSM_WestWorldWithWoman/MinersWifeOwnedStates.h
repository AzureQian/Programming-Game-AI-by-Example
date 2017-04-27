#ifndef MINERSWIFE_OWNED_STATES_H
#define MINERSWIFE_OWNED_STATES_H

#include "State.h"

class MinersWife;

class WifesGlobalState : public State<MinersWife>
{
private:

	WifesGlobalState(){}

	WifesGlobalState(const WifesGlobalState&);
	WifesGlobalState& operator=(const WifesGlobalState&);

public:

	static WifesGlobalState* Instance();

	virtual void Enter(MinersWife* wife) {};
	virtual void Execute(MinersWife* wife);
	virtual void Exit(MinersWife* wife) {};
};

class DoHouseWork : public State<MinersWife>
{
private:

	DoHouseWork() {}

	DoHouseWork(const DoHouseWork&);
	DoHouseWork& operator=(const DoHouseWork&);

public:

	static DoHouseWork* Instance();

	virtual void Enter(MinersWife* wife);
	virtual void Execute(MinersWife* wife);
	virtual void Exit(MinersWife* wife);
};

class VisitBathroom : public State<MinersWife>
{
private:

	VisitBathroom() {}

	VisitBathroom(const VisitBathroom&);
	VisitBathroom& operator=(const VisitBathroom&);

public:

	static VisitBathroom* Instance();

	virtual void Enter(MinersWife* wife);
	virtual void Execute(MinersWife* wife);
	virtual void Exit(MinersWife* wife);
};

#endif

