#include <iostream>
#include <algorithm>

using namespace std;

void knapsack(int n, int w[], int v[], int W) 
{
    int cur_weight = 0;  // current weight in knapsack
    double max_profit = 0.0;  // maximum profit obtained

    // calculate profit/weight ratio for each item
    double pw[n];
    for (int i = 0; i < n; i++) 
	{
        pw[i] = (double)v[i] / w[i];
    }

    // sort items in decreasing order of profit/weight ratio
    for (int i = 0; i < n; i++) 
	{
        for (int j = i+1; j < n; j++) 
		{
            if (pw[i] < pw[j]) 
			{
                swap(pw[i], pw[j]);
                swap(w[i], w[j]);
                swap(v[i], v[j]);
            }
        }
    }

    // select items for knapsack
    for (int i = 0; i < n; i++) 
	{
        if (cur_weight + w[i] <= W) 
		{  // add entire item to knapsack
            cur_weight += w[i];
            max_profit += v[i];
        } 
		else 
		{  // add fractional item to knapsack
            int remaining_weight = W - cur_weight;
            double fraction = (double)remaining_weight / w[i];
            max_profit += fraction * v[i];
            break;
        }
    }

    cout << "Maximum profit = " << max_profit << endl;
}

int main() 
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    int w[n], v[n];
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) 
	{
        cin >> w[i] >> v[i];
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    knapsack(n, w, v, W);
    return 0;
}

