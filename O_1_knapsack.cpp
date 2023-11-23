#include <iostream>

using namespace std;
int steps = 0;

int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            steps++;
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (wt[i - 1] > w)
                dp[i][w] = dp[i - 1][w];
            else
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    }

    return dp[n][W];
}

int main()
{
    int W,wt[10],val[10],i,n;
    cout<< "Enter knapsack capacity: ";
    cin>> W;

    cout<<"Enter number of items: ";
    cin>> n;

    cout<<"\nEnter weight and values of each items: \n";

    for(i=0;i<n;i++)
    {
        cout<<"W["<<i+1<<"] = : ";
        cin>>wt[i];
        cout<<"V["<<i+1<<"] = : ";
        cin>>val[i];
        cout<<"\n";
    }

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;

    cout<<"Steps taken = " <<steps <<endl;

    return 0;
}

