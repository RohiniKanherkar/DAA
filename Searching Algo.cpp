#include <vector>
#include <iostream>
#include <algorithm>  // Include the algorithm library for the 'sort' function
using namespace std;

void linearsearch(int arr[], int n, int search_ele) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search_ele) {
            cout << "\nElement " << search_ele << " found at index " << i << endl;
            return;  // Once found, exit the function
        }
    }
    cout << "Element " << search_ele << " not found in the array using linear search." << endl;
}

void Binarysearch(int arr[], int n, int search_ele) {
    int s = 0;
    int e = n - 1;
    int mid;
    while (s <= e) {  // Use '<=' to include both endpoints
        mid = (s + e) / 2;
        if (search_ele == arr[mid]) {
            cout << "\nElement " << search_ele << " found at index " << mid << endl;
            return;  // Once found, exit the function
        }
        if (search_ele < arr[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    cout << "Element " << search_ele << " not found in the array using iterative binary search." << endl;
}

int BinarysearchRecursive(int arr[], int search_ele, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        if (search_ele == arr[mid])
            return mid;
        if (search_ele < arr[mid])
            return BinarysearchRecursive(arr, search_ele, start, mid - 1);
        return BinarysearchRecursive(arr, search_ele, mid + 1, end);
    }
    return -1;  // Element not found
}

int main() 
{
    int n, search_ele;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    cout << "\nEnter an element to be searched: ";
    cin >> search_ele;

    int choice,ch=1;
    while(ch!=0)
    {
         cout<<"\n1.Linear Search\n2.Binary search iterative\n3.Binary search Recursive\n\tEnter your choice : ";
         cin>>choice;
        switch(choice)
        {
            case 1:
                linearsearch(arr.data(), n, search_ele);
                break;
                
            case 2:
                Binarysearch(arr.data(), n, search_ele);
                break;
            
            case 3:
                sort(arr.begin(), arr.end());
                int result = BinarysearchRecursive(arr.data(), search_ele, 0, n - 1);
            
                if (result != -1) {
                    cout << "Element " << search_ele << " found at index " << result << "." << endl;
                } else {
                    cout << "Element " << search_ele << " not found in the array using recursive binary search." << endl;
                }
                break;
                
            Default:
                break;
        }
    }
    cout<<"\nDo you want to continue (0/1) : ";
    cin>>ch;
    return 0;
}



OUTPUT:

5
1 2 3 4 5
Enter an element to be searched: 3
1.Linear Search
2.Binary search iterative
3.Binary search Recursive
	Enter your choice : 1
	Element 3 found at index 2

1.Linear Search
2.Binary search iterative
3.Binary search Recursive
	Enter your choice : 2
	Element 3 found at index 2

1.Linear Search
2.Binary search iterative
3.Binary search Recursive
	Enter your choice : 3
	Element 3 found at index 2.
