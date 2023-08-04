#include<iostream>
using namespace std;

void insert_withoutreplacement(int n)
{
	int arr1[n-1];//for storing entered elememts
	int arr2[n-1];//main hash table //-1
	int flag[n-1];//if double values appears  //0
	
	cout<<"\nENTER THE ELEMENTS : "<<endl;
	for(int i=0; i<n; i++)//for storing entered elements
	{
		cin>>arr1[i];
	}
	
	for(int i=0; i<n; i++)//main hash table
	{
		arr2[i]=-1;
	}
	
	for(int i=0; i<n; i++)//for double index value
	{
		flag[i]=0;
	}
	
	for(int i=0; i<n; i++)
	{
		int a=arr1[i]%n;
		
		if(arr2[a]==-1)
		{
			arr2[a]=arr1[i];
			flag[a]=1;
		}
		else
		{
			int c=a+1;
			int flag1=0;
			
			while(c!=a && flag1==0)
			{
				if(flag[c]==0 && c<n)
				{
					arr2[c]=arr1[i];
					flag[c]=1;
					flag1=1;
					break;
				}
				else
				{
					if(c==n)
					{
						c=-1;
					}
					c++;
				}
				
			}
		}
	}
	
	
	cout<<"Hashing table :"<<endl;
	for(int j=0; j<n; j++)
	{
		cout<<arr2[j]<<" ";
	}
}


void insert_withreplacement(int n)
{
	int arr1[n-1];
	int arr2[n-1];
	int flag[n-1];
	
	
	for(int i=0; i<n; i++)
	{
		cin>>arr1[i];
	}
	
	for(int i=0; i<n; i++)
	{
		arr2[i]=-1;
	}
	
	for(int i=0; i<n; i++)
	{
		flag[i]=0;
	}
	
	for(int i=0; i<n; i++)
	{
		int a=arr1[i]%n;
		
		if(arr2[a]==-1)
		{
			arr2[a]=arr1[i];
			flag[a]=1;
		}
		else
		{
			int c=a+1;
			int flag1=0;
			
			while(c != a && flag1==0)
			{
				if(flag[c]==0 && c<n)
				{
					arr2[c]=arr1[i];
					flag[c]=1;
					flag1=1;
					//swapping
					int temp;
					temp=arr2[a];
					arr2[a]=arr2[c];
					arr2[c]=temp;
					c++;
					break;
				}
				else
				{
					if(c==n)
					{
						c=-1;
					}
					c++;
				}
			}
			
		}
	}
	
	cout<<"Hashing table :"<<endl;
	for(int j=0; j<n; j++)
	{
		cout<<"\n|  "<<arr2[j]<<"  |";
	}
}



int main()
{
	int n1,n2,ch='y',choice;
	
	do
	{
		cout<<"\n\tHashing techniques";
		cout<<"\n\t1. Hashing without replacement"<<endl;
		cout<<"\t2. Hashing with replacement"<<endl;
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the size of Hashing table : ";
				cin>>n1;
				insert_withoutreplacement(n1);
				break;
				
			case 2:
				cout<<"Enter the size of Hashing table : ";
				cin>>n2;
				insert_withreplacement(n2);
				break;
			
			default:
				cout<<"Please enter correct choice!!"<<endl;
			break;
		}
		cout<<"\n\nWANT TO ENTER ONE MORE CHOICE? ";
		cin>>ch;
	}
	while(ch==y);
	
	return 0;
}/*
#include<iostream>
using namespace std;

void insert_withoutreplacement(int n)
{
	int arr1[n-1];
	int arr2[n-1];
	int flag[n-1];
	
	cout<<"ENTER THE ELEMENTS : ";
	for(int i=0; i<n; i++)
	{
		cin>>arr1[i];
	}
	
	for(int i=0; i<n; i++)
	{
		flag[i]=0;
	}
	
	for(int i=0; i<n; i++)
	{
		arr2[i]=-1;
	}
	
	for(int i=0; i<n; i++)
	{
		int a=arr1[i]%n;
		if(arr2[a]==-1)
		{
			arr2[a]=arr1[i];
			flag[a]=1;
		}
		else
		{
			int c=a+1;
			int flag1=0;
			
			while(c!=a && flag1==0)
			{
				if(flag[c]==0 && c<n)
				{
					arr2[c]=arr1[c];
					flag[c]=1;
					flag1=1;
				}
				else
				{
					if(c==n)
					{
						c=-1;
					}
					c++;
				}
			}
		}
	}
	cout<<"Hashing table : "<<endl;
	for(int j=0; j<n; j++)
	{
		cout<<arr2[j]<<" ";
	}
	
}



void insert_withreplacement(int n)
{
	int arr1[n-1];
	int arr2[n-1];
	int flag[n-1];
	
	cout<<"Enter the elements : ";
	for(int i=0; i<n; i++)
	{
		cin>>arr1[i];
	}
	
	for(int i=0; i<n; i++)
	{
		arr2[i]=-1;
	}
	for(int i=0; i<n; i++)
	{
		flag[i]=0;
	}
	
	for(int i=0; i<n; i++)
	{
		int a=arr1[i]%n;
		if(arr2[a]==-1)
		{
			arr2[a]=arr1[i];
			flag[a]=1;
		}
		else
		{
			int c=a+1;
			int flag1=0;
			
			while(c!=a && flag1==0)
			{
				if(flag[c]==0 && c<n)
				{
					arr2[c]=arr1[i];
					flag[c]=1;
					flag1=1;
					
					int temp;
					temp=arr2[a];
					arr2[a]=arr1[c];
					arr1[c]=temp;
					c++;
					break;
				}
				else
				{
					if(c==n)
					{
						c=-1;
					}
					c++;
				}
			}
			
		}
	}
	cout<<"Hashing table : ";
	for(int j=0; j<n; j++)
	{
		cout<<arr2[j]<<" ";
	}
	
}





int main()
{
	int n1,n2,ch=1,choice;
	
	do
	{
		cout<<"\t1. HASHING WITHOUT REPLACEMENTS"<<endl;
		cout<<"\t2. HASHING WITH REPLACEMENT"<<endl;
		cout<<"ENTER YOUR CHOICE : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"ENTER MAXIMUM SIZE OF HASHING TABLE : ";
				cin>>n1;
				
				insert_withoutreplacement(n1);
				break;
				
			case 2:
				cout<<"ENTER MAXIMUM SIZE OF HASHING TABLE : ";
				cin>>n2;
				
				insert_withreplacement(n2);
				break;
			
			default:
				cout<<"Please enter correct choice!! "<<endl;	
		}
		
		cout<<"\nDo you want to continue?"<<endl;
		cin>>ch;
	}
	while(ch==1);
	
	return 0;
	
}

*/
