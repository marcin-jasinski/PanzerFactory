#include "Tracklying.h"

Tracklying::Tracklying(const Engine& eng, const Tower& tow, const Cannon& can, double TrLen) : Panzer(eng, tow, can)
{
	this->tracksLength = TrLen;
}

Tracklying::~Tracklying() {};

// this operator is called from within a subclass << operator
std::ostream & operator<<(std::ostream & outFile, const Tracklying & tracklying)
{
	outFile << "Tracks length: " << tracklying.tracksLength << std::endl;
	return outFile;
}
