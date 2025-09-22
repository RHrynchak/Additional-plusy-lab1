#include "random.h"

std::mt19937& Random::engine()
{
	static std::mt19937 eng{
		[] {
			std::random_device rd;
			std::seed_seq seeds{ rd(), rd(), rd(), rd(), rd(), rd() };
			return std::mt19937(seeds);
		}()
	};

	return eng;
}
