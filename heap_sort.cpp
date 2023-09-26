#include <iostream>
using namespace std;

int counter=0;

void heapify(int arr[], int n, int rootIndex)
{
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    counter++;

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != rootIndex)
    {
        swap(arr[rootIndex], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[20];
    int i, n;

    cout<<"Enter size of list: ";
    cin>>n;

    cout<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Enter element " << i+1 <<" : ";
        cin>>arr[i];
    }

    heapSort(arr, n);

    cout<< "\nSorted Array\n>> [ ";
    for(i=0;i<n;i++)
    {
        cout <<arr[i] << " " ;
    }
    cout<< "]\n";

    cout<<"\nSteps = " <<counter <<endl;

    return 0;
}
