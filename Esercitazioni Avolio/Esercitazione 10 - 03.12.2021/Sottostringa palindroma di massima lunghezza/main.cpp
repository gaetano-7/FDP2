#include <iostream>
#include <string>
using namespace std;
string s;
const int SIZE = 1000;
int dp[SIZE][SIZE];

int longestPalindrom(int i, int j);
int main()
{
    
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            dp[i][j] = -1;

    cin >> s;

    cout << longestPalindrom(0, s.size() - 1);
}

// mtioristam
// mtiritm 

int longestPalindrom(int i, int j){

    /*se i == j -> 1
    se i > j -> 0
    se i < j 
        se s[i] == s[j] -> 2 + longestPalindrom(i+1, j-1)
        se s[i] != s[j] -> max(longestPalindrom(i+1,j),longestPalindrom(i,j-1)
    */        
    if(dp[i][j] != -1)
        return dp[i][j];

    if(i == j)
        return 1;

    if(i > j)
        return 0;
    
    if(s[i] == s[j]){
        dp[i][j] = 2 + longestPalindrom(i+1, j-1);
        return dp[i][j];
    }else{
        dp[i][j] = max(longestPalindrom(i+1, j), longestPalindrom(i, j-1));
        return dp[i][j];
    }
    return 0;
}
//asam i = 1 j = 3


