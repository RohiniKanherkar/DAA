// C++ program to illustrate time point
// and system clock functions
#include <bits/stdc++.h>
#include<cstring>
#include<iostream> 
using namespace std;
#include <chrono>
#include <ctime>

#define INF 9999999
#define V 5
int G[V][V];
// Driver code
int main()
{
	// Using time point and system_clock
	std::chrono::time_point<std::chrono::system_clock> start, end;

    int no_edge ;
	int cost_path ;
	int selected[V];
	no_edge = 0;
	int i,j,V1;
	
	std::cout<<"\nENTER NUMBER OF VERTICES : ";
	std::cin>>V1;
	std::cout<<"\nENTER THE COST OF ADJ MATRIX : ";
	for(i=0 ; i<V1 ; i++)
	{
		for(j=0 ; j<V1 ; j++) 
		{
			cin>>G[i][j];
		}
	}
	selected[0]=true;
	int x;
	int y;
	
	std::cout<<"EDGE\t"<<" : "<<"WEIGHT"<<endl;
	start = std::chrono::system_clock::now();
	
	 while(no_edge < V1-1)
	{
		int min = INF;
		x = 0;
		y = 0;
		for(i=0 ; i<V1 ; i++)
		{
			if(selected[i])
			{	
				for(j=0 ; j<V1 ; j++)
				{
					if(!selected[j] && G[i][j])
					{
						if(min > G[i][j])
						{
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
	
		std::cout<< x <<" - "<< y <<"   :   "<<G[x][y]<<endl;
		cost_path = cost_path + G[x][y];
		selected[y] = true;
		no_edge++;
	}
	
	std::cout<<"\nMINIMUM COST PATH: "<<cost_path;
		
		
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "\nFinished computation at " << std::ctime(&end_time)
			<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}


