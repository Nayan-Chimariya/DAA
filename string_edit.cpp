#include <iostream>
#include <algorithm>
using namespace std;

int steps =0;

int editDistance(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            steps ++;
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
             else
             {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],     // Delete
                    dp[i][j - 1],     // Insert
                    dp[i - 1][j - 1]  // Replace
                });
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout<< "Enter string 1: ";
    cin>> str1;
    cout<< "Enter string 2: ";
    cin >> str2;

    cout << "\nMinimum number of operations: " << editDistance(str1, str2) << endl;
    cout<< "\nSteps taken = " <<steps <<endl;

    return 0;
}

