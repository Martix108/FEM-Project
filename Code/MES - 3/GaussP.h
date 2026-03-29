#pragma once
#include <vector>
#include <cmath>

struct Gauss2P {
	std::vector<double> nodes = { -1.0 / sqrt(3.0), 1.0 / sqrt(3.0) };
	std::vector<double> coefficients = { 1.0, 1.0 };
};

struct Gauss3P {
	std::vector<double> nodes = { -sqrt(3.0 / 5.0), 0 , sqrt(3.0 / 5.0) };
	std::vector<double> coefficients = { 5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0 };
};

struct Gauss4P {
	std::vector<double> nodes = { -0.861136, -0.339981, 0.339981, 0.861136 };
	std::vector<double> coefficients = { 0.347855, 0.652145, 0.652145, 0.347855 };
};