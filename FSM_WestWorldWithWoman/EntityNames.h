#ifndef NAMES_H
#define NAMES_H

#include <string>

enum
{
	ent_Miner_Bob,
	ent_Elsa,
	ent_num	// 习惯这么写了，虽然不知是否会用到
};

inline std::string GetNameOfEntity(int n)
{
	switch (n)
	{
	case ent_Miner_Bob:
		return "Miner Bob";
	case ent_Elsa:
		return "Elsa";
	default:
		return "UNKNOWN";
	}
}

#endif