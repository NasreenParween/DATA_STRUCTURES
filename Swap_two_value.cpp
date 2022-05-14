/*  C++ Program to Swap two value  */

#include<iostream>
using namespace std;

void swap(int,int);

int main()
{
        int a,b;
        cout<<"Enter Value Of A : ";
        cin>>a;
        cout<<"\nEnter Value of B : ";
        cin>>b;

        cout<<"\nBefore Swapping, Value of :: \n\tA = "<<a<<"\tB = "<<b<<"\n";

        swap(a,b);

        cout<<"\n Outside Function After Swapping, Value of : \n\tA = "<<a<<"\tB = "<<b<<"\n";
}


void swap(int a,int b)
{
        int c;
        c=a;
        a=b;
        b=c;
        cout<<"\n Inside Function After Swapping, Value of ::\n\tA = "<<a<<"\tB = "<<b<<"\n";
}
