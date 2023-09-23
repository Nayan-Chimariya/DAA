#include <iostream>
using namespace std;

void printList(int A[], int n)
{
    int i;
    cout<< ">> [ ";
    for(i=0;i<n;i++)
    {
        cout <<A[i] << " " ;
    }
    cout<< "]\n";
}

int bubbleSort(int A[], int n)
{
    int i, j, bubble_count=0;

    cout<< "\nBubble Sort\n";
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            bubble_count ++;
            if(A[j]>A[j+1])
                swap(A[j],A[j+1]);
        }
    }

    printList(A,n);
    return bubble_count;
}

int selectionSort(int A[], int n)
{
    int min_value, min_index, i, j, selection_counter = 0;

    cout<< "\nSelection Sort\n";
    for(i=0;i<n-1;i++)
    {
        min_value = A[i];
        min_index = i;
        for(j=i+1;j<n;j++)
        {
            selection_counter++;
            if(A[j]<min_value)
            {
                min_value = A[j];
                min_index = j;
            }
        }

        swap(A[i],A[min_index]);
    }

    printList(A,n);
    return selection_counter;
}

int insertionSort(int A[], int n)
{
    int i, j, key, insetion_counter = 0;

    cout<< "\nInsertion Sort\n";
    for(i=1;i<n;i++)
    {
        key = A[i];
        for(j=i-1;j>=0 && A[j]>key;j--)
        {
            insetion_counter++;
            A[j+1] = A[j];
        }
        A[j+1] = key;
    }

    printList(A,n);
    return insetion_counter;
}


int main()
{
    int A1[50], A2[50], A3[50], i, n, steps;

    cout<<"Enter size of list: ";
    cin>>n;

    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Enter element " << i+1 <<" : ";
        cin>>A1[i];
    }

    for(i=0;i<n;i++)
    {
        A2[i] = A1[i];
        A3[i] = A1[i];
    }

    steps = bubbleSort(A1,n);
    cout<< "Completed in " <<steps <<" steps\n";

    steps = selectionSort(A2,n);
    cout<< "Completed in " <<steps <<" steps\n";

    steps = insertionSort(A3,n);
    cout<< "Completed in " <<steps <<" steps\n";

    return 0;
}
