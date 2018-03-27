#pragma once 
#include <vector>
#include <cmath>

using namespace std;

namespace optimization
{
	enum class function
	{
		ackley,
		schwefel,
		function3
	};

	float ackley(const vector<float> &input);
	float schwefel(const vector<float> &input);
	float function3(const vector<float> &input);

	float objective_function(function f, const vector<float> &input);
}