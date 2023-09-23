#include <iostream>
using namespace std;

int counter = 0;

int fibo(int n)
{
    int f0 = 1, f1 = 1, f, i;
    if(n==1)
    {
        counter++;
        cout<<f0;
    }

    else if(n==2)
    {
        counter+=2;
        cout<<f0 <<" " <<f1;
    }

    else
    {
        cout<<f0 <<" " <<f1;
        counter+=2;
        for(i=3;i<=n;i++)
        {
            counter++;
            f = f0+f1;
            f0 = f1;
            f1 = f;
            cout<<" " <<f;
        }
    }

    return counter;
}

int main()
{
    int n, steps;
    cout<<"Enter term: ";
    cin>>n;
    steps = fibo(n);
    cout<< "\nCompleted in " <<steps <<" steps\n";
    return 0;
}
