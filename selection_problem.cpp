#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int counter = 0;

int partition(int arr[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int findIndex(int arr[], int low, int high, int searchKey)
{
    if (low <= high)
    {
        counter++;
        int partitionIndex = partition(arr, low, high);

        if (arr[partitionIndex] == searchKey)
            return partitionIndex;

        if (arr[partitionIndex] > searchKey)
            return findIndex(arr, low, partitionIndex - 1, searchKey);

        return findIndex(arr, partitionIndex + 1, high, searchKey);
    }

    return -1;
}

int main()
{
    srand(time(nullptr));

    int A[20], num, i, key;

    cout << "Enter the number of elements: ";
    cin >> num;

    cout<<endl;
    for (i = 0; i < num; i++)
    {
        cout << "Enter "<<i + 1 <<" element: ";
        cin >> A[i];
    }


    cout << endl;

    cout<<"Search What? : ";
    cin >>key;

    int result = findIndex(A, 0, num- 1, key);

    if (result != -1)
        cout << "\nThe index of " << key << " = " << result << endl;
    else
        cout << "\nSearch key not found." << endl;

    cout << "\nSteps taken : " <<counter <<endl;

    return 0;
}
