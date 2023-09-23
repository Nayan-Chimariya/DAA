#include <iostream>
using namespace std;

int counter=0,m;

int binarySearch(int A[], int l, int r, int key)
{
    if(l<=r)
    {
        counter++;
        m = (l+r) / 2;

        if(A[m] == key)
            return m;
        else if(A[m]>key)
            return binarySearch(A,l, m-1,key);
        else
            return binarySearch(A, m+1, r, key);
    }
    return -1;
}

int main()
{
    int A[20], n, key, index;

    cout<<"Enter size of list: ";
    cin>> n;

    cout<<endl;
    for(int i =0; i<n; i++)
    {
        cout<< "Enter value " <<i+1 <<" : ";
        cin>> A[i];
    }

    cout<< "\nSearch what : ";
    cin>> key;

    index = binarySearch(A,0,n-1,key);

    if(index!=-1)
        cout<< "\nFound search value (" <<key <<") at index : " <<index <<endl;
    else
        cout<<"\nDid not find the value\n";

    cout<<"\nSteps taken = "<<counter <<endl;
}
