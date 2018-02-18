#include "Tower.h"
#include <iostream>

Tower::Tower(double ANS, int Vt, int Prc, double Wght)
{
	this->angularSpeed = ANS;
	this->vitality = Vt;
	this->price = Prc;
	this->weight = Wght;
}

Tower::~Tower()
{
	angularSpeed = 0;
	vitality = 0;
	price = 0;
	weight = 0;
}

void Tower::displayTowerSpecs()
{
	std::cout << "\nTower angular speed: " << angularSpeed;
}

int Tower::getVitality()
{
	return vitality;
}

int Tower::getPrice()
{
	return price;
}

double Tower::getWeight()
{
	return weight;
}

std::ostream & operator<<(std::ostream & outFile, const Tower & tow)
{
	outFile << "Tower angular speed: " << tow.angularSpeed << std::endl;
	return outFile;
}
