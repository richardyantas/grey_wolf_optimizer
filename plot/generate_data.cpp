#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;

// g++ -std=c++11  generate_data.cpp && ./a.out

class CPoint
{
	public:			
		float x;
		float y;
		float z;
		CPoint(int _x,int _y,int _z):x(_x),y(_y),z(_z){};
};

	
void write_on_file(const char* path,const vector<CPoint> &points)
{
	ofstream fout(path);
	for(int i = 0; i < points.size(); i++)
	{
		fout << points[i].x << " " << points[i].y << " " << points[i].z << endl;
	}		
	fout.close();

}

float ackley(const vector<float> &input)
{
	// OBS -32.768 < input[i] < 32.768		
	float a = 20, b = 0.2, c = 2*3.14;
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
		s_1 += pow(input[i],2.0);
	}
	f3 = 0.5 - (pow(sin(sqrt(s_1)),2.0)-0.5)/pow((1.0+0.001*s_1),2.0);
	return f3;
}


void fill_vector(vector<float> &x, float left_bound, float right_bound)
{
	int number_of_points = x.size();
	float delta = (right_bound - left_bound)/(number_of_points-1);

	x[0] = left_bound;
	for(int i = 1; i < number_of_points; i++)
	{
		x[i] = x[i-1] + delta;
	}

	if(x[number_of_points-1] - right_bound <= 0){ 
		cout << "OK FILLED" << endl;
	}

	/*
	for(int i = 0; i < number_of_points; i++)
	{
		cout << x[i] << endl;
	}
	*/

}

int main()
{
	int dimension     = 2;
	float left_bound  = -100.0;
	float right_bound = 100.0;
	int number_of_points = 100;

	vector<float> x1(number_of_points,0);
	vector<float> x2(number_of_points,0);

	fill_vector(x1,left_bound,right_bound);
	fill_vector(x2,left_bound,right_bound);

	vector<vector<float>> grid;  // in c++11 there are not a problem but in c++ need to change, separate <>


	for(int i = 0; i < number_of_points; i++)
	{
		//cout << x2[i] << endl;
	}	

	for(int i = 0; i < number_of_points; i++)
	{
		vector<float> x(2);
		for(int j = 0; j < number_of_points; j++)
		{			
			x[0] = x1[i];
			x[1] = x2[j];
			grid.push_back(x);	
		}		
		x.clear();
	}


	/*
	ofstream fout("10000_points_function3.txt");

	cout << grid.size() << endl;

	for(int i = 0; i < grid.size(); i++)
	{
		//fout << grid[i][0] << " " << grid[i][1] << " " << function3(grid[i]) << endl;
		//cout << grid[i][0] << " " << grid[i][1] << " " << ackley(grid[i]) << endl;
		//cout << ackley(grid[i]) << endl;
	}
	fout.close();
	*/
	
	vector<float> p(2,1);
	cout << function3( p ) << endl;

	return 0;
}	