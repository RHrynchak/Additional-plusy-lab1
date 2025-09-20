#include "random.h"

Random::Random()
{
	std::random_device rd;
	eng_ = std::mt19937(rd());
}

Random::Random(unsigned int seed)
{
	eng_ = std::mt19937(seed);
}
