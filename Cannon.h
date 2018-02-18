#pragma once
#include <fstream>

class Cannon
{
private:
	int RateOfFire;
	double maxRange;
	double gauge;

	int vitality;
	int price;
	double weight;

public:
	Cannon(int, double, double, int, int, double);
	~Cannon();

	int getVitality();
	int getPrice();
	double getWeight();

	void displayCannonSpecs();

	friend std::ostream & operator << (std::ostream&, const Cannon&);
};