#include <iostream>
#include <climits>

using namespace std;
int steps = 0;

int matrixChainMultiplication(int dimensions[], int n)
{

    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        steps++;
        dp[i][i] = 0;
    }

    for (int chainLen = 2; chainLen < n; chainLen++)
    {
        for (int i = 1; i < n - chainLen + 1; i++)
        {
            int j = i + chainLen - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                steps++;
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int dimensions[10], i, n;

    cout<<"Number of dimensions: ";
    cin>>n;

    cout<< "\nEnter dimensions : \n";

    for(i=0; i<n; i++)
        cin>>dimensions[i];

    cout << "\nMinimum number of scalar multiplications: " << matrixChainMultiplication(dimensions, n) <<endl;

    cout<<"\nSteps taken = " <<steps <<endl;

    return 0;
}
