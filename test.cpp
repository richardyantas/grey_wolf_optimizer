#include<iostream>
#include "utils.h"
#include "benchmark_functions.h"
#include "grey_wolf_optimizer.h"
using namespace std;
using namespace optimization;
int main()
{
	optimization::function f = optimization::function::ackley;
	solution s = grey_wolf_optimizer(f,100,3,-32768.0,32768.0,3);

	for(int i = 0; i < s.convergence.size(); i++ )
	{
		cout << s.convergence[i] << endl;
	}

	cout << "time: " <<  s.time_of_execution << endl;
	cout << "best: " <<  s.best << endl;

	return 0;
}