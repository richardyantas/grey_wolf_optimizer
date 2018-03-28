#include <iostream>
#include <fstream>
#include "utils.h"
#include "benchmark_functions.h"
#include "grey_wolf_optimizer.h"
using namespace std;
using namespace optimization;
int main()
{

	//optimization::function f = optimization::function::ackley;
	
/*	solution grey_wolf_optimizer(function f, int max_number_of_evaluations,
		int number_of_agents, float left_bound, float right_bound,int dimension);
*/

	/*

	// 45
	for(int n = 4; n < 100; n++)
	{
		solution s = grey_wolf_optimizer(f,50,n,-32.768,32.768,2);	
		cout << "it: " << n << endl;
		cout << s.best << endl;
		for(int i = 0; i < s.best_pos.size(); i++)
		{
			cout << s.best_pos[i] << " ";
		}
		cout << endl;
		cout << "convergence: " << endl;
		for(int i = 0; i < s.convergence.size(); i++)
		{
			cout << s.convergence[i] << " ";
		}
		cout << endl;
	}
	*/
	
	/*
	ofstream fout1("ackley_2.txt");
	ofstream fout2("ackley_8.txt");

	for(int it = 0; it < 100; it++)
	{
		solution s = grey_wolf_optimizer(f,100,45,-32.768,32.768,2);

		for(int i = 0; i < s.best_pos.size(); i++)
		{
			fout1 << s.best_pos[i] << " ";
		}
		fout1 << s.best << endl;

		solution s2 = grey_wolf_optimizer(f,100,45,-32.768,32.768,8);

		for(int i = 0; i < s2.best_pos.size(); i++)
		{
			fout2 << s2.best_pos[i] << " ";
		}
		fout2 << s2.best << endl;
		
	}

	fout1.close();
	fout2.close();
	*/



	optimization::function f = optimization::function::schwefel;

	for(int n = 4; n < 100; n++)
	{
		solution s = grey_wolf_optimizer(f,100,n,-500.0,500.0,2);	
		cout << "it: " << n << endl;
		cout << s.best << endl;
		for(int i = 0; i < s.best_pos.size(); i++)
		{
			cout << s.best_pos[i] << " ";
		}
		cout << endl;
		/*
		cout << "convergence: " << endl;
		for(int i = 0; i < s.convergence.size(); i++)
		{
			cout << s.convergence[i] << " ";
		}
		cout << endl;
		*/
	}	
/*
	ofstream fout1("schwefel_2.txt");
	ofstream fout2("schwefel_8.txt");

	for(int it = 0; it < 100; it++)
	{
		solution s = grey_wolf_optimizer(f,100,45,-32.768,32.768,2);

		for(int i = 0; i < s.best_pos.size(); i++)
		{
			fout1 << s.best_pos[i] << " ";
		}
		fout1 << s.best << endl;

		solution s2 = grey_wolf_optimizer(f,100,45,-32.768,32.768,8);

		for(int i = 0; i < s2.best_pos.size(); i++)
		{
			fout2 << s2.best_pos[i] << " ";
		}
		fout2 << s2.best << endl;
		
	}

	fout1.close();
	fout2.close();
*/		
	
	return 0;
}