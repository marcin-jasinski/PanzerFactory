#pragma once
#include <fstream>

class Tower
{
private:
	double angularSpeed;

	int vitality;
	int price;
	double weight;

public:
	Tower(double, int, int, double);
	~Tower();

	int getVitality();
	int getPrice();
	double getWeight();

	void displayTowerSpecs();

	friend std::ostream& operator << (std::ostream&, const Tower&);
};