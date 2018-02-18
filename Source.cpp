#include <iostream>
#include <fstream> // files
#include <vector>
#include <string>
#include <typeinfo> // typeid

#include "Panzer.h"
#include "InfantryFightingVehicle.h"
#include "Tank.h"
#include "TankDestroyer.h"

int main()
{
	std::fstream magazine;
	magazine.open("hangar.txt", std::ios::out | std::ios::trunc);
	if (!magazine.good())
	{
		std::cerr << "Error opening magazine file.";
		std::cin.ignore(1);
		return 1;
	}
	
	std::cout << "<== PANZER FACTORY ==>" << std::endl;
	std::cout << "======================" << std::endl;

	std::cout << "Place created vehicles in hangar only after creating all desired vehicles." << std::endl;

	// Engine(Horse power, torque, capacity, vitality, price, weight)
	Engine availableEngines[] = {
		Engine(1500, 3700, 47500.25, 100, 18000, 450.1),
		Engine(1650, 3855, 49670.72, 100, 20000, 510.5),
		Engine(1725, 4000, 48670.18, 100, 25000, 511.25)
	};

	// Tower(Angular speed, vitality, price, weight)
	Tower availableTowers[] = {
		Tower(18.2, 100, 100, 75.4),
		Tower(20.5, 100, 110, 80.4),
		Tower(21.5, 100, 150, 73.4)
	};

	// Cannon(Rate of fire, range, gauge, vitality, price, weight)
	Cannon availableCannons[] = {
		Cannon(6, 1500.5, 120.12, 100, 100, 80.2),
		Cannon(7, 2000.13, 115.23, 100, 100, 80.2),
		Cannon(10, 2230.54, 110.2, 100, 100, 80.2)
	};

	std::vector<Panzer*> hangar; // vector storage for created panzer vehicles

	int x;
	// user interface
	do
	{
		std::cout << "\nChoose one of the following: " << std::endl;
		std::cout << "1 - display each panzer vehicle summary number." << std::endl;
		std::cout << "2 - display detailed panzer specs from hangar." << std::endl;
		std::cout << "3 - create new panzer vehicle. " << std::endl;
		std::cout << "4 - save all created vehicles to hangar." << std::endl;
		std::cout << "5 - terminate program." << std::endl;

		std::cin >> x;
		
		// getting initial counters values
		int IFWc = InfantryFightingVehicle::getIFWcounter();
		int	Tankc = Tank::getTankCounter();
		int	TDc = TankDestroyer::getTDC();

		switch (x)
		{
		case 1:
		{
			std::cout << "\nInfantry Fighting Vehicles: " << IFWc << std::endl;
			std::cout << "Tanks: " << Tankc << std::endl;
			std::cout << "Tank destroyers: " << TDc << std::endl;
			break;

		}
			
		case 2:
		{
			if (IFWc == 0 && Tankc == 0 && TDc == 0) std::cout << "\nHangar is empty!" << std::endl;
			else for (auto h : hangar) h->showPanzerSpecs();
			break;
		}

		case 3:
		{
			std::cout << "\nCreating new panzer vehicle." << std::endl;
			std::cout << "Infantry Fighting Vehicle - 1" << std::endl;
			std::cout << "Tank - 2" << std::endl;
			std::cout << "Tank destroyer - 3" << std::endl;
			int panz;
			std::cin >> panz;

			// choosing components
			std::cout << "\nChoose engine: " << std::endl;
			for (auto e : availableEngines)
			{
				e.displayEngineSpecs();
				std::cout << std::endl;
			}
			int eng;
			std::cin >> eng;
			std::cout << "\nChoose tower: " << std::endl;
			for (auto t : availableTowers)
			{
				t.displayTowerSpecs();
				std::cout << std::endl;
			}
			int tow;
			std::cin >> tow;
			std::cout << "\nChoose cannon: " << std::endl;
			for (auto c : availableCannons) 
			{
				c.displayCannonSpecs();
				std::cout << std::endl;
			}
			int can;
			std::cin >> can;

			Panzer* bufferPanzer = NULL; // nullptr used for dynamic panzer vahicles creation
			if (panz == 1)
			{
				bufferPanzer = new InfantryFightingVehicle(availableEngines[eng-1], availableTowers[tow-1], availableCannons[can-1], 10, 7);
				hangar.push_back(bufferPanzer);
			}
			if (panz == 2)
			{
				bufferPanzer = new Tank(availableEngines[eng-1], availableTowers[tow-1], availableCannons[can-1], 25.15, 10);
				hangar.push_back(bufferPanzer);
			}
			if (panz == 3)
			{
				bufferPanzer = new TankDestroyer(availableEngines[eng-1], availableTowers[tow-1], availableCannons[can-1], 18.90, 1500);
				hangar.push_back(bufferPanzer);
			}
			break;
		}

		case 4:
		{	
			for (auto h : hangar)
			{
				// uses typeid to get class name from an object and compare it with an already known one
				// if types match, cast h which is in fact Panzer* to appropriate class pointer, dereference it and write the whole thing to file
				if (typeid(InfantryFightingVehicle) == typeid(*h)) magazine << *(dynamic_cast<InfantryFightingVehicle*>(h)) << std::endl;
				if (typeid(Tank) == typeid(*h)) magazine << *(dynamic_cast<Tank*>(h)) << std::endl;
				if (typeid(TankDestroyer) == typeid(*h)) magazine << *(dynamic_cast<TankDestroyer*>(h)) << std::endl;

				std::cout << "\n\nVehicles saved." << std::endl;
			}
			break;
		}

		case 5:
			std::cout << "\nProgram will now terminate." << std::endl;
			break;

		default:
			std::cerr << "\nWrong vaule. Try again." << std::endl;
			break;
		}
	} while (x != 5);
	
	magazine.close();

	std::cin.ignore(2);
	return 0;
}

