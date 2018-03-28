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

	double ackley(const vector<double> &input);
	double schwefel(const vector<double> &input);
	double function3(const vector<double> &input);

	double objective_function(function f, const vector<double> &input);
}