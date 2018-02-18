#include "Panzer.h"
#include <iostream>

// constructor of class Panzer takes references to engine, tower and cannon objects as arguments to shorten its initialization list
Panzer::Panzer(const Engine & eng, const Tower & tow, const Cannon & can) : engine(eng), tower(tow), cannon(can)
{
	totalVitality = engine.getVitality() + tower.getVitality() + cannon.getVitality();
	summaryPrice = engine.getPrice() + tower.getPrice() + cannon.getPrice();
	totalWeight = engine.getWeight() + tower.getWeight() + cannon.getWeight();
}

Panzer::~Panzer() {};

void Panzer::showPanzerSpecs()
{
	engine.displayEngineSpecs();
	tower.displayTowerSpecs();
	cannon.displayCannonSpecs();
}

int Panzer::getTotalVitality() const
{
	return totalVitality;
}

int Panzer::getSummatyPrice() const
{
	return summaryPrice;
}

double Panzer::getTotalWeight() const
{
	return totalWeight;
}

std::ostream & operator<<(std::ostream & outFile, const Panzer & panzer)
{
	outFile << panzer.engine << panzer.tower << panzer.cannon; // calling << operator for each object
	outFile << "Total vitality: " << panzer.getTotalVitality() << std::endl;
	outFile << "Summary price: " << panzer.getSummatyPrice() << std::endl;
	outFile << "Total weight: " << panzer.getTotalWeight() << std::endl;
	return outFile;
}
