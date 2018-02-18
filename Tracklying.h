#pragma once
#include "Panzer.h"

class Tracklying : public Panzer
{
private:
	double tracksLength;

public:
	Tracklying(const Engine&, const Tower&, const Cannon&, double);
	virtual ~Tracklying();

	friend std::ostream& operator << (std::ostream&, const Tracklying&);
};

