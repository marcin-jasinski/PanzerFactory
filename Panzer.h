#pragma once
#include "Engine.h"
#include "Cannon.h"
#include "Tower.h"

class Panzer
{
	Engine engine;
	Tower tower;
	Cannon cannon;

	int totalVitality;
	int summaryPrice;
	double totalWeight;

public:
	Panzer(const Engine&, const Tower&, const Cannon&);
	virtual ~Panzer();

	// getters need to be "const" because of const reference in << operator
	int getTotalVitality() const;
	int getSummatyPrice() const;
	double getTotalWeight() const;

	virtual void showPanzerSpecs(); // polymorphic function different for each panzer vehicle type

	friend std::ostream& operator << (std::ostream&, const Panzer&);
};