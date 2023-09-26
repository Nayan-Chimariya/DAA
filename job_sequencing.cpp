#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_JOBS = 100;
int counter = 0;

void jobSequencing(int jobIds[], int profits[], int deadlines[], int n)
{
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, deadlines[i]);

    int result[MAX_JOBS];

    for (int i = 0; i < maxDeadline; i++)
        result[i] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            counter++;
            if (profits[i] < profits[j])
            {
                swap(profits[i], profits[j]);
                swap(deadlines[i], deadlines[j]);
                swap(jobIds[i], jobIds[j]);
            }
        }
    }

    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int deadline = deadlines[i] - 1;

        while (deadline >= 0 && result[deadline] != -1)
        {
            counter++;
            deadline--;
        }

        if (deadline >= 0)
        {
            counter++;
            result[deadline] = jobIds[i];
            totalProfit += profits[i];
        }
    }

    cout << "Job sequence with maximum profit: ";
    for (int i = 0; i < maxDeadline; i++)
    {
        if (result[i] != -1)
            cout << result[i] << " ";

    }
    cout << endl;
    cout << "Total profit: " << totalProfit << endl;
}

int main()
{
    int n, i;
    int jobIds[MAX_JOBS];
    int profits[MAX_JOBS];
    int deadlines[MAX_JOBS];

    cout << "Enter the number of jobs: ";
    cin >> n;

    cout << "\nEnter the job IDs, profits, and deadlines\n\n";
    for (i = 0; i < n; i++)
    {
        cout<< "Job        ["<<i+1 <<"]\n---------------\nID        : ";
        cin >> jobIds[i];
        cout<<"Profit    : ";
        cin>> profits[i];
        cout<<"Deadlines : ";
        cin>>deadlines[i];
        cout<<"\n";
    }

    jobSequencing(jobIds, profits, deadlines, n);
    cout<<"\nSteps [calculation + swapping ] = " <<counter <<endl;
    return 0;
}
