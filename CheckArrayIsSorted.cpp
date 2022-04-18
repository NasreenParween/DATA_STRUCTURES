/* Program to check if array is sorted or not */
#include<iostream>
using namespace std;
int main()
{
    /* Scan size of array */
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;

    /* Scan Array Elements */
    int arr[n];
    cout<<"\nEnter array elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int temp = 0;
    for(int i = 1; i < n; i++)
    {
        /* If array is not sorted */
        if(arr[i] < arr[i-1])
        {
            temp = 1;
            break;
        }
    }

    if(temp == 1)
    cout<<"\nArray is not sorted!!";
    else
    cout<<"\nArray is sorted!!";

}
