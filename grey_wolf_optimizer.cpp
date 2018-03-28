#include "grey_wolf_optimizer.h"
#include "utils.h"
#include "benchmark_functions.h"
#include <limits>
#include <iostream>
#include <fstream>
#include <exception>
#include <cmath>

#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;

namespace optimization
{
	solution grey_wolf_optimizer(function f, int max_number_of_iterations,int number_of_agents, double left_bound, double right_bound,int dimension)
	{
		vector<double> alpha_pos(dimension,0);
		vector<double> beta_pos(dimension,0);
		vector<double> delta_pos(dimension,0);

		double alpha_score = numeric_limits<double>::infinity();
		double beta_score  = numeric_limits<double>::infinity();
		double delta_score = numeric_limits<double>::infinity();

		auto positions = get_initial_positions(left_bound, right_bound, dimension, number_of_agents); // vector<vector<double>> 
		solution s;

		//const int max_number_of_iterations{max_number_of_evaluations/number_of_agents};

	    std::ofstream fout1("../00_guiding_points.txt");
	    std::ofstream fout2("../01_following_points.txt");
		int iteration = 0;
		//while(iteration++ < max_number_of_iterations) // Esto tambien esta mal
		while(iteration < max_number_of_iterations)
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

	        // Escribimos en un archivo las diferentes posiciones de alfa beta y delta
	       	FOR(i,dimension)
	       		fout1 << alpha_pos[i] << " ";
	       	fout1 << objective_function(f,alpha_pos) << endl;

	       	FOR(i,dimension)
	       		fout1 << beta_pos[i] << " ";
	       	fout1 << objective_function(f,beta_pos) << endl;

	       	FOR(i,dimension)
	       		fout1 << delta_pos[i] << " ";
	       	fout1 << objective_function(f,delta_pos) << endl;

	       	// Escribimos todas las posiciones de los lobos
	       	FOR(i,number_of_agents){
	       		FOR(dim,dimension)
	       			fout2 << positions[i][dim] << " ";
	       		fout2 << objective_function(f,positions[i]) << endl;
	       	}



	        //double a = get_random(0., 1.) * 2.; //Este calculo esta mal
	        double a = 3.0 - iteration * ( 3.0 / (double) max_number_of_iterations );

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

	                agent[j] = (X1*0.5 + X2*0.3 + X3*0.2) / 1.;
	            }

	        s.convergence.push_back(alpha_score);
	        s.best = alpha_score;

	        iteration++;

		}// Fin del Bucle While
	       	
		fout1.close();
		s.best_pos = alpha_pos;
		return s;
	}
}