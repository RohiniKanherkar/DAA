/*#include <iostream>
using namespace std;


void insertionSort(int *array, int arraySize) 
{
  	for (int i = 1; i < arraySize; i++) 
	{
    	int key = array[i];
    	int j = i - 1;
    	
		while (j >= 0 && array[j] > key) 
		{
	      	array[j + 1] = array[j];
	      	j--;
    	}
    	array[j + 1] = key;
  	}
}

void divideIntoSubgroups(int *arr, int arrSize, int subgroupSize) 
{
  	int subgroupCount = (arrSize + subgroupSize - 1) / subgroupSize;
  	int index = 0;
  	
  	for (int i = 0; i < subgroupCount; i++) 
	{
	    int subgroupEnd = min(index + subgroupSize, arrSize);
	    int subgroupSize = subgroupEnd - index;
	    int subgroup[subgroupSize];
	    
	    for (int j = 0; j < subgroupSize; j++, index++) 
		{
	      subgroup[j] = arr[index];
	    }
	    //Apply insertion sort to sort the each subgroup
		insertionSort(subgroup, subgroupSize);
	    
		cout << "List " << i + 1 << ": ";
	    for (int j = 0; j < subgroupSize; j++) 
		{
	      cout << subgroup[j] << " ";
	    }
	    cout <<endl;
  	}
}

int main() 
{
	int n;
	cout<<"\nEnter array size : ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"\n\nElements of the array are \n\t";
	for(int i=0; i<n; i++)
	{
		cout<<" "<<arr[i];
	}
  	int arrSize = sizeof(arr) / sizeof(arr[0]);
  	int subgroupSize = 5;
  	cout<<"\n\nDividing a array into 5 elemets.."<<endl;
  	divideIntoSubgroups(arr, arrSize, subgroupSize);
  	
	  //Apply sort to each list
	
  	
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;

int medianOfMedians(int arr[], int n)
{
    if (n <= 5)
    {
        sort(arr, arr + n);
        return arr[n / 2];
    }

    int i;
    int median[(n + 4) / 5]; // Divide the elements into groups of 5
    for (i = 0; i < n / 5; i++)
    {
        sort(arr + i * 5, arr + i * 5 + 5);
        median[i] = arr[i * 5 + 2];
    }

    // For the last group with less than 5 elements
    if (i * 5 < n)
    {
        sort(arr + i * 5, arr + n);
        median[i] = arr[(i * 5 + n - 1) / 2];
        i++;
    }

    // Find median of the medians recursively
    return medianOfMedians(median, i);
}
    
void swapping( int *a,int *b)
{
 int temp = *a;
	*a = *b;
	*b = temp;
}

int  pariton(int arr[], int lb, int ub)
{
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	
	
	while(start<end)
	{
		while(arr[start]<=pivot)
		{
			start++;
		}
		
		while(arr[end]>pivot)
		{
			end--;
		}
		
		if(start<end)
		{
			swapping(&arr[start],&arr[end]);
			
		}
	}
	swapping(&arr[lb],&arr[end]);
	
	return end;
}


void quicksort(int arr[], int lb,int ub)

{
	if(lb<ub)
	{
		int spt=pariton(arr,lb,ub);
		quicksort(arr,lb,spt-1);
		quicksort(arr,spt+1,ub);
	}
}

int main()
{ 
  auto start = chrono::high_resolution_clock::now();
    std::cout<<"\n+--------------------------------------------------+"<<endl;
    std::cout<<"\t     Median of Median Algorithm \n"<<endl;
    std::cout<<"\n+--------------------------------------------------+"<<endl;
    int n;
    std::cout<<"Enter size of the array : ";
    std::cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=rand()%100;
    }
    std::cout<<"\n+------------------------------------------------------------------------+"<<endl;
    std::cout<<"\nGiven Array : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
	std::cout<<"\n+------------------------------------------------------------------------+"<<endl;
	int lb=0,ub=n-1;
	medianOfMedians(arr, n);
	quicksort(arr, lb,ub);
	
	std::cout<<"\nApplying Median Of Median Algorithm......"<<endl;
	cout<<"The sorted array is: "<<endl;
	for( int i = 0 ; i < n; i++)
	{
		cout<< arr[i]<<"\t";
	}
	std::cout<<"\n+------------------------------------------------------------------------+"<<endl;
	cout<<endl;
	auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

return 0;
	
}
