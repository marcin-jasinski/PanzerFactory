#pragma once
#include "Tracklying.h"
#include <string>

class Tank : public Tracklying
{
private:
	static int tankCounter;

	std::string name;
	double reloadTime;

public:
	Tank(const Engine&, const Tower&, const Cannon&, double, double, std::string name = "Tank numer ");
	~Tank();

	static int getTankCounter();

	void showPanzerSpecs();

	friend std::ostream& operator << (std::ostream&, const Tank&);
};

