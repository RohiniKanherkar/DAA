#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    int deadline[n], profit[n];
    for(int i=0; i<n; i++) {
        cout << "Enter deadline and profit for job " << i+1 << ": ";
        cin >> deadline[i] >> profit[i];
    }

    // sort jobs in descending order of profit
    for(int i=0; i<n-1; i++) 
	{
        for(int j=0; j<n-i-1; j++) 
		{
            if(profit[j] < profit[j+1]) 
			{
                swap(profit[j], profit[j+1]);
                swap(deadline[j], deadline[j+1]);
            }
        }
    }

    int max_deadline = *max_element(deadline, deadline+n);
    int slots[max_deadline] = {0};
    int total_profit = 0;

    // allocate jobs to time slots
    for(int i=0; i<n; i++) 
	{
        int j = deadline[i] - 1;
        while(j >= 0 && slots[j] != 0) 
		{
            j--;
        }
        if(j >= 0) 
		{
            slots[j] = 1;
            total_profit += profit[i];
        }
    }

    cout << "Total profit: " << total_profit << endl;

    return 0;
}

