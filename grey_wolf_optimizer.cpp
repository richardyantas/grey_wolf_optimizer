#include "grey_wolf_optimizer.h"
#include "utils.h"
#include "benchmark_functions.h"
#include <limits>
#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

namespace optimization
{
	solution grey_wolf_optimizer(function f, int max_number_of_evaluations,int number_of_agents, float left_bound, float right_bound,int dimension)
	{
		vector<float> alpha_pos(dimension,0);
		vector<float> beta_pos(dimension,0);
		vector<float> delta_pos(dimension,0);

		float alpha_score = numeric_limits<float>::infinity();
		float beta_score  = numeric_limits<float>::infinity();
		float delta_score = numeric_limits<float>::infinity();


		auto positions = get_initial_positions(left_bound, right_bound, dimension, number_of_agents);
		solution s{};
		int iteration{0};

		const int max_number_of_iterations{max_number_of_evaluations/number_of_agents};

		while(iteration++ < max_number_of_iterations)
		{
			clip_positions(positions, left_bound, right_bound);

	        for (auto &agent : positions)
	        {
	            double fitness = objective_function(f, agent);

	            if (fitness < alpha_score)
	            {
	                alpha_score = fitness;
	                alpha_pos = agent;
	            }

	            if (fitness > alpha_score and fitness < beta_score)
	            {
	                beta_score = fitness;
	                beta_pos = agent;
	            }

	            if (fitness > alpha_score and fitness > beta_score and fitness < delta_score)
	            {
	                delta_score = fitness;
	                delta_pos = agent;
	            }
	        }

	        double a = get_random(0., 1.) * 2.;

	        for (auto &agent : positions)
	            for (auto j = 0u; j < agent.size(); ++j)
	            {
	                // alpha
	                double r1 = get_random(0., 1.);
	                double r2 = get_random(0., 1.);

	                double A1 = 2. * a * r1 - a;
	                double C1 = r1 * 2.;

	                const double D_alpha = std::abs(C1 * alpha_pos[j] - agent[j]);
	                const double X1 = alpha_pos[j] - A1 * D_alpha;

	                // beta
	                r1 = get_random(0., 1.);
	                r2 = get_random(0., 1.);

	                double A2 = 2. * a * r1 - a;
	                double C2 = r1 * 2.;

	                const double D_beta = std::abs(C2 * beta_pos[j] - agent[j]);
	                const double X2 = beta_pos[j] - A2 * D_beta;

	                // delta
	                r1 = get_random(0., 1.);
	                r2 = get_random(0., 1.);

	                double A3 = 2. * a * r1 - a;
	                double C3 = r1 * 2.;

	                const double D_delta = std::abs(C3 * delta_pos[j] - agent[j]);
	                const double X3 = delta_pos[j] - A3 * D_delta;

	                agent[j] = (X1 + X2 + X3) / 3.;
	            }

	        s.convergence.push_back(alpha_score);
	        s.best = alpha_score;
		}
		return s;
	}
}