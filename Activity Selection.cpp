#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;

int n;
int start[MAX], finish[MAX];

void activitySelection()
{
    // Sort activities based on finish time
    for (int i = 0; i < n; i++) 
	{
        for (int j = i+1; j < n; j++) 
		{
            if (finish[i] > finish[j]) 
			{
                swap(start[i], start[j]);
                swap(finish[i], finish[j]);
            }
        }
    }

    int i = 0;
    cout << "Selected Activities: ";
    cout << "(" << start[i] << ", " << finish[i] << "), ";

    for (int j = 1; j < n; j++) 
	{
        if (start[j] >= finish[i]) 
		{
            cout << "(" << start[j] << ", " << finish[j] << "), ";
            i = j;
        }
    }
}

int main()
{
    cout << "Enter the number of activities: ";
    cin >> n;

    cout << "Enter the start and finish time of each activity:\n";
    for (int i = 0; i < n; i++) 
	{
        cin >> start[i] >> finish[i];
    }

    activitySelection();

    return 0;
}

