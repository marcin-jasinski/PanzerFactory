#include "Cannon.h"
#include <iostream>

Cannon::Cannon(int ROF, double range, double gauge, int Vt, int Prc, double Wght)
{
	this->RateOfFire = ROF;
	this->maxRange = range;
	this->gauge = gauge;

	this->vitality = Vt;
	this->price = Prc;
	this->weight = Wght;
}

Cannon::~Cannon()
{
	RateOfFire = 0;
	maxRange = 0;
	gauge = 0;
	vitality = 0;
	price = 0;
	weight = 0;
}

void Cannon::displayCannonSpecs()
{
	std::cout << "\nRate of Fire (per minute): " << RateOfFire;
	std::cout << "\nMax missile range (km)   : " << maxRange;
	std::cout << "\nMissile gauge (mm)       : " << gauge;
}

int Cannon::getVitality()
{
	return vitality;
}

int Cannon::getPrice()
{
	return price;
}

double Cannon::getWeight()
{
	return weight;
}

std::ostream & operator<<(std::ostream & outFile, const Cannon & can)
{
	outFile << "Rate of fire: " << can.RateOfFire << std::endl;
	outFile << "Range: " << can.maxRange << std::endl;
	outFile << "Gauge: " << can.gauge << std::endl;
	return outFile;
}
