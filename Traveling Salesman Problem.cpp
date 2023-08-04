#include <iostream>
#include <algorithm>

using namespace std;

const int N = 4;
const int INF = 1e9;

int dist[N][N] = {{0, 10, 15, 20},
		          {10, 0, 35, 25},
		          {15, 35, 0, 30},
		          {20, 25, 30, 0}};

int tsp(int start, int visited, int current, int cnt, int path[]) 
{
    if(cnt == N) 
	{ // all cities visited
        return dist[current][start];
    }
    int ans = INF;
    for(int i = 0; i < N; i++) 
	{
        if(!(visited & (1<<i))) 
		{ // if i-th city is not visited
            path[cnt] = i;
            ans = min(ans, dist[current][i] + tsp(start, visited | (1<<i), i, cnt+1, path));
        }
    }
    return ans;
}

int main() 
{
    int path[N];
    int ans = INF;
    int start = 0; // starting city
    for(int i = 0; i < N; i++) 
	{
        path[0] = i; // set first city in path
        ans = min(ans, dist[start][i] + tsp(start, 1<<i, i, 1, path));
    }
    cout << "Minimum distance: " << ans << endl;
    cout << "Path: ";
    cout <<endl<< start <<" " ; // add starting city at the end
    for(int i = 0; i < N; i++) 
	{
        cout << path[i] << " ";
    }
    
    return 0;
}

