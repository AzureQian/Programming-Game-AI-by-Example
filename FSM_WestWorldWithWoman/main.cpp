#include <fstream>
#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"

std::ofstream os;


int main()
{
#ifdef TEXTOUTPUT
	os.open("output.txt")
#endif	

	Miner Bob(ent_Miner_Bob);
	MinersWife Elsa(ent_Elsa);

	for(int i = 0; i < 20; ++i)
	{
		Bob.Update();
		Elsa.Update();

		Sleep(500);
	}

	PressAnyKeyToContinue();

	return 0;
}
