#include "InfantryFightingVehicle.h"
#include <iostream>

int InfantryFightingVehicle::IFWcounter = 0;

InfantryFightingVehicle::InfantryFightingVehicle(const Engine& eng, const Tower& tow, const Cannon& can, int sold, int emb, std::string name) : Panzer(eng, tow, can)
{
	IFWcounter++;
	name += std::to_string(IFWcounter);
	this->name = name;
	this->maxSoldiersInside = sold;
	this->firingEmbrasuresNumber = emb;
}

InfantryFightingVehicle::~InfantryFightingVehicle()
{
	maxSoldiersInside = 0;
	firingEmbrasuresNumber = 0;
	IFWcounter--;
}

int InfantryFightingVehicle::getMaxSoldiersNumber()
{
	return maxSoldiersInside;
}

int InfantryFightingVehicle::getFiringEmbrasuresNumber()
{
	return firingEmbrasuresNumber;
}

int InfantryFightingVehicle::getIFWcounter()
{
	return IFWcounter;
}

void InfantryFightingVehicle::showPanzerSpecs()
{
	std::cout << "\n\n" << name;
	Panzer::showPanzerSpecs();
	std::cout << "\nTotal vitality: " << getTotalVitality();
	std::cout << "\nSummary price:  " << getSummatyPrice();
	std::cout << "\nTotal weight:   " << getTotalWeight();
	std::cout << "\nMax soldiers inside: " << maxSoldiersInside;
	std::cout << "\nFiring embrasures: " << firingEmbrasuresNumber << std::endl;
}

std::ostream & operator<<(std::ostream & outFile, const InfantryFightingVehicle & IFW)
{
	outFile << IFW.name << std::endl;
	outFile << *(Panzer*)&IFW;	// casting needed to call << operator for base Panzer class
	outFile << "Max soldiers inside: " << IFW.maxSoldiersInside << std::endl;
	outFile << "Firing embrasures: " << IFW.firingEmbrasuresNumber << std::endl;
	return outFile;
}
