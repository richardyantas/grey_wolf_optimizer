#include "utils.h"
#include <boost/algorithm/clamp.hpp>
#include <random>
#include <vector>
using namespace std;

namespace optimization
{
	double get_random(double left_bound, double right_bound)
	{
		static random_device rd;
		static mt19937 gen(rd());
		uniform_real_distribution<double> dist(left_bound,right_bound);
		return dist(gen);
	}

	vector< vector<double> >  get_initial_positions(double left_bound, double right_bound, int dimension, int number_of_agents)
	{
		vector< vector<double> > positions(number_of_agents, vector<double>(dimension,0.));
		for(auto &agent : positions)
		{
			for(auto &coord : agent)
			{
				coord = get_random(left_bound,right_bound);
			}
		}
		return positions;
	}

	vector< vector<double> > &clip_positions(vector<vector<double>> &positions, double left_bound, double right_bound)
	{
		for (auto &agent : positions)
    	    for (auto &coord : agent)
        	    coord = boost::algorithm::clamp(coord, left_bound, right_bound);
	    return positions;
	}

}