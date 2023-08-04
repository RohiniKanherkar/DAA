#include<iostream>
using namespace std;

void heapify_asc(int arr[], int n, int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && arr[l] > arr[largest])
		largest=l;
	if(r<n && arr[r] > arr[largest])
		largest=r;
		
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
	}
}


void heapify_des(int arr[], int n, int i)
{
	int smallest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && arr[l] < arr[smallest])
		smallest=l;
	if(r<n && arr[r] < arr[smallest])
		smallest=r;
		
	if(smallest != i)
	{
		swap(arr[i],arr[smallest]);
	}
}

void heapsort_asc(int arr[], int n)
{
	for(int i=n/2-1; i>=0; i--)
		heapify_asc(arr,n,i);
	
	for(int i=n-1; i>0; i--)
	{
		swap(arr[0],arr[i]);
		heapify_asc(arr,i,0);
	}
}

void heapsort_des(int arr[], int n)
{
	for(int i=n/2-1; i>=0; i--)
		heapify_des(arr,n,i);
	
	for(int i=n-1; i>0; i--)
	{
		swap(arr[0],arr[i]);
		heapify_des(arr,i,0);
	}
}

void display(int arr[],int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"  ";
	}
}
int main()
{
	int n,i,arr[30];
	
	cout<<"ENTER HOW MANY ELEMENTS YOU WANT TO INSERT?   ";
	cin>>n;
	
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	cout<<"+-----------HEAPSORT OPERATIONS -------------+"<<endl;
	heapsort_asc(arr,n);
	cout<<"\n+---------------ASCENDING ORDER--------------+"<<endl;
	display(arr,n);
	heapsort_des(arr,n);
	cout<<"\n\n+---------------DESENDING ORDER--------------+"<<endl;
	display(arr,n);
	return 0;
}




/*

#include<iostream>
using namespace std;


void heapify_asc(int arr[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
		
	if(largest != i)
	{
		swap(arr[i],arr[largest]);	
	}	
}


void heapify_des(int arr[],int n,int i)
{
	int smallest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && arr[l]<arr[smallest])
		smallest=l;
	if(r<n && arr[r]<arr[smallest])
		smallest=r;
		
	if(smallest != i)
	{
		swap(arr[i],arr[smallest]);	
	}	
}

void heapsort_asc(int arr[],int n)
{
	for(int i=n/2-1; i>=0; i--)
		heapify_asc(arr,n,i);
	
	for(int i=n-1; i>0; i--)
	{
		swap(arr[0],arr[i]);
		heapify_asc(arr,i,0);	
	}
}

void heapsort_des(int arr[],int n)
{
	for(int i=n/2-1; i>=0; i--)
		heapify_des(arr,n,i);
	
	for(int i=n-1; i>0; i--)
	{
		swap(arr[0],arr[i]);
		heapify_des(arr,i,0);
	}
}


void display(int arr[],int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"  ";
	}
}
int main()
{
	int n,i,arr[20],choice;
	
	cout<<"How many elements you want to enter ? ";
	cin>>n;
	
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}

	cout<<" \tHeapsort Operations"<<endl;
	heapsort_asc(arr,n);
	cout<<"\nAscending order : "<<endl;
	display(arr,n);
	
	heapsort_des(arr,n);
	cout<<"\nDesending order : "<<endl;
	display(arr,n);
	
	return 0;
}*/
