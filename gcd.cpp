#include <iostream>
using namespace std;

int counter = 0;

int gcd(int a, int b)
{
    int r;
    if(b>a)
        swap(a,b);
    while(b!=0)
    {
        counter++;
        r = a % b;
        a = b;
        b = r;
    }

    cout<< "GCD : " <<a;
    return counter;
}

int main()
{
    int a, b, step;
    cout<<"Enter two numbers: ";
    cin>>a >>b;

    step = gcd(a,b);
    cout<<"\nCompleted in " <<step <<" Steps\n";

    return 0;
}
