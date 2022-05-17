#include<iostream>
using namespace std;
main()
{
    cout<<"Enter the size of the array:";
    int size;
    cin>>size;
    int arr[size];
    int i,temp=0;
    cout<<"Enter the Element of the array:\n";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int ele;
    cout<<"\nEnter the search element:";
    cin>>ele;
    cout<<"\nArray elements are:";
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    int index;
    for(i=0;i<size;i++)
    {
        if(arr[i]==ele)
        {
            temp=1;
            index=i;
        }
    }
    if(temp==1)
        cout<<"\nIndex of Search Element "<<ele<<" is "<<index;
    else
        cout<<"\nElement not found....";
}
