#include "MinerOwnedStates.h"
#include "State.h"
#include "Miner.h"
#include "Locations.h"
#include "EntityNames.h"
#include "misc/ConsoleUtils.h"
#include <iostream>

using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

EnterMinerAndDigForNugget* EnterMinerAndDigForNugget::Instance()
{
	static EnterMinerAndDigForNugget instance;
	return &instance;
}

void EnterMinerAndDigForNugget::Enter(Miner* pMiner)
{
	if(pMiner->Location() != goldmine)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' to the goldmine";
		
		pMiner->ChangeLocation(goldmine);
	}
}

void EnterMinerAndDigForNugget::Execute(Miner* pMiner)
{
	pMiner->AddToGoldCarried(1);

	pMiner->IncreaseFatigue();

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Pickin' up a nugget";

	if(pMiner->PocketsFull())
	{
		pMiner->ChanegState(VisitBankAndDepositGold::Instance());
	}
	else if(pMiner->Thirsty())
	{
		pMiner->ChanegState(QuenchThirst::Instance());
	}
}

void EnterMinerAndDigForNugget::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Ah'm leavin' the goldmine with mah pockets full o' sweet gold";
}


VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* pMiner)
{
	if(pMiner->Location() != bank)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Goin' to the bank. Yes siree";

		pMiner->ChangeLocation(bank);
	}
}

void VisitBankAndDepositGold::Execute(Miner* pMiner)
{
	pMiner->AddToWealth(pMiner->GoldCarried());

	pMiner->SetGoldCarried(0);

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Depositing gold. Total savings now: " << pMiner->Wealth();

	if(pMiner->Wealth() >= ComfortLevel)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "WooHoo! Rich enough for now. Back home to mah li'lle lady";

		pMiner->ChanegState(GoHomeAndSleepTilRestored::Instance());
	}
	else
	{
		pMiner->ChanegState(EnterMinerAndDigForNugget::Instance());
	}
}

void VisitBankAndDepositGold::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leavin' the bank";
}

GoHomeAndSleepTilRestored* GoHomeAndSleepTilRestored::Instance()
{
	static GoHomeAndSleepTilRestored instance;
	return &instance;
}


void GoHomeAndSleepTilRestored::Enter(Miner* pMiner)
{
	if(pMiner->Location() != shack)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Walkin' home";
		pMiner->ChangeLocation(shack);
	}
}

void GoHomeAndSleepTilRestored::Execute(Miner* pMiner)
{
	if(!pMiner->Fatigued())
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "What a God darn fantastic nap! Time to find more gold";

		pMiner->ChanegState(EnterMinerAndDigForNugget::Instance());
	}
	else
	{
		pMiner->DecreaseFatigue();
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "ZZZZ... ";
	}
}

void GoHomeAndSleepTilRestored::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the house";
}

QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Miner* pMiner)
{
	if(pMiner->Location() != saloon)
	{
		pMiner->ChangeLocation(saloon);
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Boy, ah sure is thusty! Walking tp the saloon";
	}
}

void QuenchThirst::Execute(Miner* pMiner)
{
	if(pMiner->Thirsty())
	{
		pMiner->BuyAndDrinkWhiskey();
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "That's mighty fine sippin liquer";
		pMiner->ChanegState(EnterMinerAndDigForNugget::Instance());
	}
	else
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\nERROR!\nERROR!\nERROR!";
	}
}

void QuenchThirst::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the saloon, feelin' good";
}





