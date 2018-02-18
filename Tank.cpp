#include "Tank.h"
#include <iostream>
#include <string>

int Tank::tankCounter = 0;

Tank::Tank(const Engine & eng, const Tower & tow, const Cannon & can, double tracks, double relTim, std::string name) : Tracklying(eng, tow, can, tracks)
{
	tankCounter++;
	name += std::to_string(tankCounter);
	this->name = name;
	this->reloadTime = relTim;
}

Tank::~Tank()
{
	reloadTime = 0;
	tankCounter--;
}

int Tank::getTankCounter()
{
	return tankCounter;
}

void Tank::showPanzerSpecs()
{
	std::cout << "\n\n" << name;
	Panzer::showPanzerSpecs();
	std::cout << "\nTotal vitality: " << Panzer::getTotalVitality();
	std::cout << "\nSummary price:  " << Panzer::getSummatyPrice();
	std::cout << "\nTotal weight:   " << Panzer::getTotalWeight();
	std::cout << "\nReload time: " << reloadTime << std::endl;
}

std::ostream & operator<<(std::ostream & outFile, const Tank & tank)
{
	outFile << tank.name << std::endl;
	outFile << *(Panzer*)&tank; // casting needed to call << operator for base Panzer class
	outFile << *(Tracklying*)&tank; // same here
	outFile << "Reload time: " << tank.reloadTime << std::endl;
	return outFile;
}
