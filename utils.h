#pragma once 

#include<iostream>
#include<vector>
using namespace std;

namespace optimization
{
	// get_initial_positions
	struct solution
	{
		vector<double> convergence;
		int time_of_execution;
		double best;
		vector<double> best_pos;
	};


	double get_random(double left_bound, double right_bound);
	// clip_positions

	vector< vector<double> > get_initial_positions(double left_bound, double right_bound, int dimension, int number_of_agents);
	vector< vector<double> > &clip_positions(vector<vector<double>> &positions, double left_bound, double right_bound);

}