#include "random.h"

Random::Random()
{
	std::random_device rd;
	std::seed_seq seeds{ rd(), rd(), rd(), rd(), rd(), rd() };
	eng_ = std::mt19937(seeds);
}

Random::Random(unsigned int seed)
{
	std::seed_seq seeds{ seed };
	eng_ = std::mt19937(seeds);
}
