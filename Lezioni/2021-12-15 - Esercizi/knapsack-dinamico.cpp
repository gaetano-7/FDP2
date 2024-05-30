// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(const vector<int>& C, const vector<int>& V, int CMax)
{
    int i, w, n=V.size();
	vector<vector<int>> K(n+1, vector<int>(CMax+1));
 
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= CMax; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (C[i - 1] <= w)
                K[i][w] = max(K[i - 1][w - C[i - 1]]+ V[i - 1],
                              K[i - 1][w]);
		// N.B., C[i - 1] e V[i - 1] invece di C[i], V[i] perché K ha una 
		// riga/colonna in più
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][CMax];
}
 
// Driver Code
int main()
{
    vector<int> V = { 60, 100, 120 };
    vector<int> C= { 10, 20, 30 };
    int CMax = 50;

     
    cout << knapSack(C,V,CMax);
     
    return 0;
}
