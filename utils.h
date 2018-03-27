#pragma once 

#include<iostream>
#include<vector>
using namespace std;

namespace optimization
{
	// get_initial_positions
	struct solution
	{
		vector<float> convergence;
		int time_of_execution;
		float best;
	};

	float get_random(float left_bound, float right_bound);
	// clip_positions

	vector< vector<float> > get_initial_positions(float left_bound, float right_bound, int dimension, int number_of_agents);
	vector< vector<float> > &clip_positions(vector<vector<float>> &positions, float left_bound, float right_bound);
}