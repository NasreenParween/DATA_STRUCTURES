#include <iostream>
using namespace std;

void ArrRev ( int [], int);
int main ()
{
    int arr[50], num, i, j, temp;
    cout << " Number of elements to be entered: " << endl;
    cin >> num;

    cout << " Enter the array elements: " << endl;

    for ( i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    cout << " Elements are: \n";
    for ( i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    ArrRev (arr, num);

    cout << " \n The reverse of the given array is: \n";
    for ( i = 0; i < num ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

void ArrRev ( int ar[], int a2)
{
    int i, j, temp;
    j = a2 - 1;
    for ( i = 0; i < j; i++, j--)
    {
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }
}
