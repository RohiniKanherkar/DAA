//dynamic
#include <iostream>
using namespace std;

int max(int x, int y) 
{
   return (x > y) ? x : y;
}

int knapSack(int W, int w[], int v[], int n) 
{
   int i, wt;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++) 
   {
      for (wt = 0; wt <= W; wt++) 
	  {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (w[i - 1] <= wt)
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
      }
   }
   return K[n][W];
}

int main() 
{
   int n, W;
   int v[n], w[n];
    cout<<"\n+--------------------------------------------------+"<<endl; 
    cout << "\nEnter the number of items in knapsack : ";
    cin >> n;
   for (int i = 0; i < n; i++) 
   {
   		cout<<"\nFor item "<<i+1<<" =>";
      	cout << "\tEnter Value : " ;
      	cin >> v[i];
      	cout << "\t\tEnter Weight : " ;
      	cin >> w[i];
   }
   cout << "\nEnter the Capacity of knapsack :";
   cin >> W;
   cout<<"\nApplying Fractional Knapsack Algorithm..."<<endl;
   cout<<"\nTotal Cost = ";
   cout << knapSack(W, w, v, n);
   cout<<"\n\n+--------------------------------------------------+"<<endl;
   
   return 0;
}
