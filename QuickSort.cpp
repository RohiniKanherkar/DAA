#include<iostream>
using namespace std;

int partition(int arr[],int l, int r)
{
	int temp,pivot;
	int i=l;
	int j=r;
	int p=l;
	pivot = arr[p];
	while(i<j)
	{
		while(arr[i]<=pivot && i<=r)
			i++;
		while(arr[j]>pivot && j>=l)
			j--;
		if(i<j)
		{
			temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[p];
	arr[p]=arr[j];
	arr[j]=temp;
	return j;
}

void quick_sort(int arr[], int l, int r)
{
	if(l<r)
	{
		int p;
		p=partition(arr,l,r);
		quick_sort(arr,l,p-1);
		quick_sort(arr,p+1,r);
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
	
	quick_sort(arr,0,n-1);
	cout<<"\n\nAfter applying Quick Sort Elements of the array are \n\t";
	for(int i=0; i<n; i++)
	{
		cout<<" "<<arr[i];
	}
	
	return 0;

}
/*

#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

int partition(int arr[],int l, int r)
{
	int temp,pivot;
	int i=l;
	int j=r;
	int p=l;
	pivot = arr[p];
	while(i<j)
	{
		while(arr[i]<=pivot && i<=r)
			i++;
		while(arr[j]>pivot && j>=l)
			j--;
		if(i<j)
		{
			temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[p];
	arr[p]=arr[j];
	arr[j]=temp;
	return j;
}

void quick_sort(int arr[], int l, int r)
{
	if(l<r)
	{
		int p;
		p=partition(arr,l,r);
		quick_sort(arr,l,p-1);
		quick_sort(arr,p+1,r);
	}
}

int main()
{
    int n;
    std::cout<<"\n+-----------------------------------------------------------------------+"<<endl;
    std::cout<<"\n\t\t\t\t\t\tQuick Sort Algotihm "<<endl;
    std::cout<<"\n+-----------------------------------------------------------------------+"<<endl;
    std::cout<<"Enter size of the given array : ";
    std::cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=rand()%100;
    }
	std::cout<<"\n\nElements of the array are \n";
	for(int i=0; i<n; i++)
	{
		std::cout<<" "<<arr[i];
	}
	// Using time point and system_clock
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	
    quick_sort(arr,0,n-1); 
    std::cout<<"\n+-----------------------------------------------------------------------+"<<endl;
    std::cout<<"\nApplying Quick Sort....";
    std::cout<<"\n\nElements of the array are \n";
	for(int i=0; i<n; i++)
	{
		std::cout<<" "<<arr[i];
	}
	
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout<<"\n+-----------------------------------------------------------------------+"<<endl;
	std::cout << "\n\nFinished computation at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n";
} 
*/
