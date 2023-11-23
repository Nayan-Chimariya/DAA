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

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void randomizedQuickSort(int arr[], int low, int high)
{

    if (low < high)
    {
        counter++;
        int pi = partition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main()
{
    srand(time(nullptr));

    int A[20], num, i;

    cout << "Enter the number of elements: ";
    cin >> num;

    cout<<endl;
    for (i = 0; i < num; i++)
    {
        cout << "Enter "<<i + 1 <<" element: ";
        cin >> A[i];
    }

    cout << endl;
    randomizedQuickSort(A, 0, num - 1);

    cout << "Randomized Quick Sort: \n";

    cout<< ">> [ ";
    for(i=0;i<num;i++)
        cout <<A[i] << " " ;
    cout<< "]\n";

    cout << "Steps taken : " <<counter <<endl;

    return 0;
}
