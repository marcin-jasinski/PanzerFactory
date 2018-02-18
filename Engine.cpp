#include "Engine.h"
#include <iostream>

Engine::Engine(int HP, int torque, double capacity, int Vt, int Prc, double Wght)
{
	this->maxHorsePower = HP;
	this->maxTorque = torque;
	this->capacity = capacity;
	this->vitality = Vt;
	this->price = Prc;
	this->weight = Wght;
}

Engine::~Engine()
{
	maxHorsePower = 0;
	maxTorque = 0;
	capacity = 0;
	vitality = 0;
	price = 0;
	weight = 0;
}

void Engine::displayEngineSpecs()
{
	std::cout << "\nCapacity (in cc): " << capacity;
	std::cout << "\nHorse Power (KM): " << maxHorsePower;
	std::cout << "\nMax Torque  (NM): " << maxTorque;
}

int Engine::getVitality()
{
	return vitality;
}

int Engine::getPrice()
{
	return price;
}

double Engine::getWeight()
{
	return weight;
}

std::ostream & operator<<(std::ostream & outFile, const Engine & eng)
{
	outFile << "Horse Power: " << eng.maxHorsePower << std::endl;
	outFile << "Torque: " << eng.maxTorque << std::endl;
	outFile << "Capacity: " << eng.capacity << std::endl;
	return outFile;
}
