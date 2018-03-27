#include "benchmark_functions.h"
#include <cmath>
#include <vector>

using namespace std;

namespace optimization
{
	float ackley(const vector<float> &input)
	{
		// OBS -32.768 < input[i] < 32.768		
		float a = 1, b = 1, c = 1;
		int   d = input.size();
		float s_1 = 0, s_2 = 0;

		for(int i = 0; i < d; i++)
		{
			s_1 += pow(input[i],2); 
			s_2 += cos(c*input[i]);  
		}
		s_1 /= d;
		s_2 /= d;

		float f1 = -a*exp(-b*sqrt(s_1)) - exp(s_2) + a + exp(1);
		return f1;
	}


	float schwefel(const vector<float> &input)
	{
		// OBS  -500 < input[i] < 500
		int d = input.size();
		float s_1 = 0;
		for(int i = 0; i < d; i++)
		{
			s_1 += input[i]*sin(sqrt(abs(input[i])));			
		}
		float f2 = 418.9829*d - s_1;
		return f2;
	}

	float function3(const vector<float> &input)
	{
		// OBS -100 < input[i] << 100
		float f3;
		int d = input.size();
		float s_1 = 0;
		for(int i = 0; i < d; i++)
		{
			s_1 += input[i];
		}
		f3 = 0.5 - (pow(sin(sqrt(s_1)),2)-0.5)/(1+0.001*s_1);
		return f3;
	}

	float objective_function(function f, const vector<float> &input)
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