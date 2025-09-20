#pragma once
#include <random>

class Random {
private:
	std::mt19937 eng_;
public:
	Random();
	Random(unsigned int seed);
	std::mt19937& engine() noexcept { return eng_; }
};