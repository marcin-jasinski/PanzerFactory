#pragma once
#include "Panzer.h"
#include <string>
#include <fstream>

class InfantryFightingVehicle : public Panzer
{
private:
	static int IFWcounter;

	std::string name;
	int maxSoldiersInside;
	int firingEmbrasuresNumber;

public:
	InfantryFightingVehicle(const Engine&, const Tower&, const Cannon&, int, int, std::string name = "IFW numer ");
	~InfantryFightingVehicle();
	
	int getMaxSoldiersNumber();
	int getFiringEmbrasuresNumber();
	static int getIFWcounter();

	void showPanzerSpecs();

	friend std::ostream& operator << (std::ostream&, const InfantryFightingVehicle&);
};



