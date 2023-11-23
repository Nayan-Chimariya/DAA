#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ITEMS = 100;
int counter = 0;

void fractionalKnapsack(int n, int capacity, int weights[], int values[])
{
    double valuePerWeight[MAX_ITEMS];
    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++)
    {
        counter++;
        valuePerWeight[i] = (values[i]) / weights[i];
    }


    while (currentWeight < capacity)
    {
        counter++;

        int bestItem = -1;
        double bestValuePerWeight = 0.0;

        for (int i = 0; i < n; i++)
        {
            counter++;
            if (weights[i] > 0 && valuePerWeight[i] > bestValuePerWeight)
            {
                bestItem = i;
                bestValuePerWeight = valuePerWeight[i];
            }
        }

        if (bestItem == -1)
            break;

        int addedWeight = min(weights[bestItem], capacity - currentWeight);
        double addedValue = addedWeight * valuePerWeight[bestItem];

        totalValue += addedValue;
        currentWeight += addedWeight;
        weights[bestItem] -= addedWeight;
    }

    cout << "Maximum value obtained: " << totalValue << endl;
}

int main()
{
    int n;
    int capacity;
    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "\nEnter the weights and values of " << n << " items:\n" << endl;

    for (int i = 0; i < n; i++)
    {
        cout<< "Item   ["<<i+1 <<"]\n----------\nWeight : ";
        cin >> weights[i];
        cout<<"Value  : ";
        cin>> values[i];
        cout<<"\n";
    }


    fractionalKnapsack(n, capacity, weights, values);

    cout<<"\nSteps [calculation of weight and values + swapping steps] = " <<counter <<endl;
    return 0;
}
