#pragma once
#include <fstream>

class Engine
{
private:
	int maxHorsePower;
	int maxTorque;
	double capacity;
	
	int vitality;
	int price;
	double weight;

public:
	Engine(int, int, double, int, int, double);
	~Engine();

	int getVitality();
	int getPrice();
	double getWeight();

	void displayEngineSpecs();

	friend std::ostream & operator << (std::ostream&, const Engine &);
};