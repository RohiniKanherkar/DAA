/*
Implement a Bloom filter for adding and look up of integer elements 
using the given Hash functions.
Hash1(key) = key % Size of Hash Table,
Hash2(key) = (key / Size of Array) % Size of Hash Table
*/

#include<iostream>
using namespace std;

// BLOOM FILTER
void bloomfilter()
{
	int n, total, h1, h2;
	int keys[10];
	int query_keys[10];
	int hash_table[10];
	
	for(int i=0; i<10; i++)
		hash_table[i] = 0; 			 // initially all values in hash table are 0
		
	cout << "\nEnter the number of keys: ";
	cin >> total;    
	cout << endl;
	
	for(int i=0; i<total; i++)
	{
		cout << "Enter the key: ";
		cin >> keys[i]; 
	}
		
	for(int i=0; i<total; i++)
	{
		
		h1 = keys[i] % 5;		// hash function 1
		hash_table[h1] = 1;
		h2 = (2*keys[i]+3)%5;	// hash function 2
		hash_table[h2] = 1;
	}
	
	cout << "\n\tHASH TABLE" << endl;	// displaying the hash table
	for(int i=0; i<10; i++)
		cout << hash_table[i] << "\t";
	cout << endl;
	
	cout << "\nEnter the total number of query keys: ";
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cout << "\nEnter query key: ";
		cin >> query_keys[i];
		
		// checking whether the query keys are present or not
		h1 = query_keys[i] % 5;			
		h2 = (2*query_keys[i]+3)%5;

		if(hash_table[h1] == 1 && hash_table[h2] == 1)
			for(int j = 0; j<total; j++)
			{
				if(query_keys[i] == keys[j])
					cout << query_keys[i] << " - is present" << endl;
				else
					cout << query_keys[i] << " - false positive" << endl;
					break;
			}
		else
			cout << query_keys[i] << " - is not present" << endl; 
		
	}
}


int main()
{
	int choice1, choice2;
	
	do{
	cout << "\n\t******" << endl;
	cout << "Bloom Filter \nSelect your choice: ";
	cin >> choice1;
	
	switch(choice1)
	{
		case 1:
			bloomfilter();
			break;
		
		default:
			cout << "\nPlease select correct choice!!" << endl;
	}
	cout << "\nDo you want to continue?(1-Yes || 0-No): ";
	cin >> choice2;
	}while(choice2==1);
	
	
	return 0;
}

