#include "utils.h"
#include <boost/algorithm/clamp.hpp>
#include <random>
#include <vector>
using namespace std;

namespace optimization
{
	float get_random(float left_bound, float right_bound)
	{
		static random_device rd;
		static mt19937 gen(rd());
		uniform_real_distribution<float> dist(left_bound,right_bound);
		return dist(gen);
	}

	vector< vector<float> >  get_initial_positions(float left_bound, float right_bound, int dimension, int number_of_agents)
	{
		vector< vector<float> > positions(number_of_agents, vector<float>(dimension,0.));
		for(auto &agent : positions)
		{
			for(auto &coord : agent)
			{
				coord = get_random(left_bound,right_bound);
			}
		}
		return positions;
	}

	vector< vector<float> > &clip_positions(vector<vector<float>> &positions, float left_bound, float right_bound)
	{
		for (auto &agent : positions)
    	    for (auto &coord : agent)
        	    coord = boost::algorithm::clamp(coord, left_bound, right_bound);
	    return positions;
	}

}