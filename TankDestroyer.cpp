#include "TankDestroyer.h"
#include <iostream>
#include <string>

int TankDestroyer::TankDestroyerCounter = 0;

TankDestroyer::TankDestroyer(const Engine & eng, const Tower & tow, const Cannon & can, double tracks, double missRang, std::string name) : Tracklying(eng, tow, can, tracks)
{
	TankDestroyerCounter++;
	name += std::to_string(TankDestroyerCounter);
	this->name = name;
	this->maxMissileRange = missRang;
}

TankDestroyer::~TankDestroyer()
{
	maxMissileRange = 0;
	TankDestroyerCounter--;
}

int TankDestroyer::getTDC()
{
	return TankDestroyerCounter;
}

void TankDestroyer::showPanzerSpecs()
{
	std::cout << "\n\n" << name;
	Panzer::showPanzerSpecs();
	std::cout << "\nTotal vitality: " << Panzer::getTotalVitality();
	std::cout << "\nSummary price:  " << Panzer::getSummatyPrice();
	std::cout << "\nTotal weight:   " << Panzer::getTotalWeight();
	std::cout << "\nMissile range: " << maxMissileRange << std::endl;
}

std::ostream & operator<<(std::ostream & outFile, const TankDestroyer & TD)
{
	outFile << TD.name << std::endl;
	outFile << *(Panzer*)&TD; // casting needed to call << operator for base Panzer class
	outFile << *(Tracklying*)&TD; // same here
	outFile << "Missile range: " << TD.maxMissileRange << std::endl;
	return outFile;
}
