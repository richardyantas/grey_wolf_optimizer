#pragma once 

#include "utils.h"
#include "benchmark_functions.h"

namespace optimization
{
	//enum class function;
	solution grey_wolf_optimizer(function f, int max_number_of_evaluations,int number_of_agents, float left_bound, float right_bound,int dimension);
}

