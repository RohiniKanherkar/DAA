#include<bits/stdc++.h>
using namespace std;

const int INF = 100000;

//k is number of denominations of the coin or length of d
int dynamic(int d[], int n, int k) //coins,amount,n
{
  	int M[n+1];
  	M[0] = 0;

	int S[n+1];
	S[0] = 0;
	
	int i, j;
	for(j=1; j<=n; j++) 
	{
	    int minimum = INF;
	    int coin=0;
	
	    for(i=1; i<=k; i++) 
		{
	      	if(j >= d[i]) 
		  	{
	        	if((1+M[j-d[i]]) < minimum) 
				{
		          	minimum = 1+M[j-d[i]];
		          	coin = i;
		        }
	     	}
	    }
	    M[j] = minimum;
	    S[j] = coin;
  	}
                                                             
  	int l = n;
  	while(l>0) 
	{
	    printf("\n Coins used are  : %d\n",d[S[l]]);
	    l = l-d[S[l]];
  	}
  	return 0;
}

int greedy(int coins[], int num, int amount) 
{
	int coin_counter = 0;
	int j = num - 1;
	sort(coins, coins + num);
	
	while(amount != 0)
	{
		if(amount >= coins[j])
		{
			coin_counter++;
			cout << "\nCoin " << coins[j] << " used\n";
			amount = amount - coins[j];
		}
		else
		{
			j--;
		}
	}
	return coin_counter;
}


int main() 
{
  	int choice;
  	do 
	{
	    cout << "1. Dynamic Programming approach\n";
	    cout << "2. Greedy approach\n";
	    cout << "3. Exit\n";
	    cout << "Enter your choice: ";
	    cin >> choice;
	    switch (choice) 
		{
	    	case 1: 
			{
	      		int n, amount;
			    cout << "Enter the number of coins denominations: ";
			    cin >> n;
			    int coins[n];
			    cout << "Enter the coins denominations: ";
		      	for (int i = 0; i < n; i++) 
				{
		        	cin >> coins[i];
		      	}
		      	cout << "Enter the amount: ";
		      	cin >> amount;
		      	dynamic(coins, amount, n);
		      	cout<<endl;
	      	break;
	    	}
	    	
	    	case 2: 
			{
		      	int n, amount;
		      	cout << "Enter the number of coins denominations: ";
		      	cin >> n;
		      	int coins[n];
		      	cout << "Enter the coins denominations: ";
		      	for (int i = 0; i < n; i++) 
				{
		        	cin >> coins[i];
		      	}
		      	cout << "Enter the amount: ";
		      	cin >> amount;
		      	cout << "Minimum number of coins required using Greedy Approach: " << greedy(coins, n, amount) << endl;
		      	break;
	    	}
	    	
	    	case 3: 
			{
		      	cout<<"Exiting ! byee ! "<<endl;
		      	break;
	    	}
	    	
			default: 
			{
	      		cout << "Invalid choice! Please try again.\n";
	    	}
	    }
  	} 
  	while (choice != 3);
  	return 0;
}

/*
dynamic
if(j >= d[i])
This line checks if the current value of j is greater than or equal to the value of the ith coin (d[i]).
 If not, then it is not possible to use that coin to reach the current value of j.


Copy code
if((1+M[j-d[i]]) < minimum)
This line calculates the minimum number of coins required to reach the value of j using the ith coin. 
It does this by looking up the number of coins required to reach the value of j-d[i] 
(i.e. the remaining amount after using the ith coin) in the M array and adding 1 to it (since we are using one more coin). 
If this value is less than the current minimum value, then it becomes the new minimum value, 
and the index of the current coin i is stored in the coin variable.


*/
