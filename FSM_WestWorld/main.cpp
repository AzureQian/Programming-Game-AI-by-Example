#include "Locations.h"
#include "Miner.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"

int main()
{
	Miner miner(ent_Miner_Bob);

	for(int i = 0; i < 20; ++i)
	{
		miner.Update();
		Sleep(800);
	}

	PressAnyKeyToContinue();

	return 0;
}