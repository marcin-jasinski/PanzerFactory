#pragma once
#include "Tracklying.h"
#include <string>

class TankDestroyer : public Tracklying
{
private:
	static int TankDestroyerCounter;

	std::string name;
	double maxMissileRange;

public:
	TankDestroyer(const Engine&, const Tower&, const Cannon&, double, double, std::string name = "Tank destroyer numer ");
	~TankDestroyer();

	static int getTDC();
	void showPanzerSpecs();

	friend std::ostream& operator << (std::ostream&, const TankDestroyer&);
};

