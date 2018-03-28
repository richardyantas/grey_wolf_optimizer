#include "benchmark_functions.h"
#include <cmath>
#include <vector>

using namespace std;

namespace optimization
{
	double ackley(const vector<double> &input)
	{
		// OBS -32.768 < input[i] < 32.768		
		double a = 20, b = 0.2, c = 2*3.14;
		int   d = input.size();
		double s_1 = 0, s_2 = 0;

		for(int i = 0; i < d; i++)
		{
			s_1 += pow(input[i],2); 
			s_2 += cos(c*input[i]);  
		}
		
		s_1 /= d;
		s_2 /= d;

		double f1 = -a*exp(-b*sqrt(s_1)) - exp(s_2) + a + exp(1);
		return f1;
	}

	double schwefel(const vector<double> &input)
	{
		// OBS  -500 < input[i] < 500
		int d = input.size();
		double s_1 = 0;
		for(int i = 0; i < d; i++)
		{
			s_1 += input[i]*sin(sqrt(abs(input[i])));			
		}
		double f2 = 418.9829*d - s_1;
		return f2;
	}

	double function3(const vector<double> &input)
	{
		// OBS -100 < input[i] << 100
		double f3;
		int d = input.size();
		double s_1 = 0;
		for(int i = 0; i < d; i++)
		{
			s_1 += pow(input[i],2.0);
		}
		f3 = 0.5 - (pow(sin(sqrt(s_1)),2.0)-0.5)/pow((1.0+0.001*s_1),2.0);
		return -f3;
	}

	double objective_function(function f, const vector<double> &input)
	{
	    switch (f)
	    {
	    case function::ackley:
	        return ackley(input);
	    case function::schwefel:
	        return schwefel(input);
	    case function::function3:
	        return function3(input);
	    }
	}

}