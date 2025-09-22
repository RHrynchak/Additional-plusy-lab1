#pragma once
#include <random>

class Random {
private:
	Random() = delete;
	Random(unsigned int seed) = delete;;
public:
	static std::mt19937& engine();
};