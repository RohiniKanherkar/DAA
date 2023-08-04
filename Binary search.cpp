//iterative
// C++ program to illustrate time point
// and system clock functions
#include <iostream>
#include <chrono>
#include <ctime>

// Function to calculate
// Fibonacci series
int bs(int arr[],int n,int search_ele)
{
	int mid;
	int low = 0;
	int high = n - 1; 
	while (low <= high)
	{
		mid = (low + high) / 2; 
		if (search_ele == arr[mid])
		{
			return mid;
		}
		if (search_ele < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	
	return -1;

}

void sorting(int n,int arr[])
{
	int i,j;
	int temp;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}


int main()
{
    int n;
    std::cout<<"Enter size of the array : ";
    std::cin>>n;
    
    int array[n];
    for(int i=0; i<n; i++)
    {
        array[i]=rand()%100;
    }
    std::cout<<"\nElements of the Array => \n ";
    for(int i=0; i<n; i++)
    {
        std::cout<<" "<<array[i];
    }
    int search_ele;
    
	// Using time point and system_clock
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	sorting(n,array);
	std::cout<<"\nSorted Array : ";
	for(int i=0; i<n; i++)
    {
        std::cout<<" "<<array[i];
    }
	std::cout<<"\nEnter a number to be search : ";
    std::cin>>search_ele;
	std::cout <<"Number "<<search_ele<< " is found at index " << bs(array,n,search_ele) << '\n';
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
} 
/*

//recursive
// C++ program to illustrate time point
// and system clock functions
#include <iostream>
#include <chrono>
#include <ctime>

// Function to calculate
// Fibonacci series
int bs(int arr[],int n,int low,int high,int search_ele)
{
	
	while (low <= high)
	{
		int mid = (low + high) / 2; 
		if (search_ele == arr[mid])
		{
			return mid;
		}
		if (search_ele < arr[mid])
		{
			return bs(arr,n,low,mid-1,search_ele);
		}
		else
		{
			return bs(arr,n,mid+1,high,search_ele);
		}
	}

}


void sorting(int n,int arr[])
{
	int i,j;
	int temp;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}


int main()
{
    int n;
    std::cout<<"Enter size of the array : ";
    std::cin>>n;
	int low = 0;
	int high = n - 1;
    int array[n];
    for(int i=0; i<n; i++)
    {
        array[i]=rand()%100;
    }
    std::cout<<"\nElements of the Array => \n ";
    for(int i=0; i<n; i++)
    {
        std::cout<<" "<<array[i];
    }
    int search_ele;
    
	// Using time point and system_clock
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	sorting(n,array);
	std::cout<<"\nSorted Array : ";
	for(int i=0; i<n; i++)
    {
        std::cout<<" "<<array[i];
    }
	std::cout<<"\nEnter a number to be search : ";
    std::cin>>search_ele;
	std::cout <<"Number "<<search_ele<< " is found at index " << bs(array,n,low,high,search_ele)<< '\n';
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}*/

