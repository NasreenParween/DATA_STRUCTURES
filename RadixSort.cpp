#include<iostream>
using namespace std;
template <class t>
class radix
{
 public:
  void print(t arr[], int n)
   {
     for(int i=0;i<n;i++)
     cout<<arr[i]<<"    ";
   }
  t getmax(t arr[],int n);
  void countsort(t arr[],int n,int place);
  void radixsort(t arr[],int n);
};
template <class t>
t radix<t>::getmax(t arr[],int n)
{
  t mx=arr[0];
  for(int i=1;i<n;i++)
   if(arr[i]>mx)
    mx=arr[i];
return mx;
}
template <class t>
void radix<t>::countsort(t arr[],int n,int place)
{
  t output[20];
  int i,count[10]={0};
  for(i=0;i<n;i++)
    count[(arr[i]/place)%10]++;
  for(i=1;i<10;i++)
    count[i]+=count[i-1];
  for(i=n-1;i>=0;i--)
  {
    output[count[(arr[i]/place)%10]-1]=arr[i];
    count[(arr[i]/place)%10]--;
  }
  for(i=0;i<n;i++)
    arr[i]=output[i];
}
template <class t>
void radix<t>::radixsort(t arr[],int n)
{
  int m;
  m=getmax(arr,n);
  for (int place=1;(m/place)>0;place*=10)
   countsort(arr,n,place);
}
int main()
{
  radix<int> r;
  int arr[40];
  int n;
  cout<<"Enter the size of array : ";
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>arr[i];

  }
  cout<<"\n unsorted Array is: ";
  r.print(arr,n);
  r.radixsort(arr,n);
  cout<<"\n Sorted Array is: ";
  r.print(arr,n);
return -1;
}
