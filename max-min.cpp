#include <iostream>
#include <algorithm>

using namespace std;

int max_num = INT_MIN, min_num = INT_MAX;

void findMaxMin(int arr[], int low, int high)
{
    // base case: only one element in the array
    if (low == high) 
	{
        max_num = arr[low];
        min_num = arr[low];
        return;
    }

    // base case: only two elements in the array
    if (high == low + 1) 
	{
        if (arr[low] < arr[high]) 
		{
            max_num = arr[high];
            min_num = arr[low];
        }
        else 
		{
            max_num = arr[low];
            min_num = arr[high];
        }
        return;
    }

    // divide the array into two halves
    int mid = (low + high) / 2;
    findMaxMin(arr, low, mid);
    findMaxMin(arr, mid + 1, high);

    // combine the results from the two halves
    max_num = max(max_num, max(arr[low], arr[high]));
    min_num = min(min_num, min(arr[low], arr[high]));
}

int main()
{
    int n, arr[100];
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }

    findMaxMin(arr, 0, n - 1);

    cout << "Maximum element: " << max_num << endl;
    cout << "Minimum element: " << min_num << endl;

    return 0;
}

