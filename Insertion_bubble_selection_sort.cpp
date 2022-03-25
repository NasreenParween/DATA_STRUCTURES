#include<iostream>
#include<process.h>
using namespace std;
const int MAX=50;
template <class T>
class sortarray{
 T arr[MAX];
 int size;
 public:
 void input();
 void insertionsort();
 void bubblesort();
 void selectionsort();
 void display();
};
template < class T>
void sortarray<T>:: input()
{
 cout<<"ENTER THE NUMBER OF ELEMENT IN ARRAY: ";
 cin>>size;
 cout<<"ENTER "<<size<<" ELEMENT IN ARRAY: "<<endl;
 for(int i=0; i<size; i++)
 {
 cin>>arr[i];
 }
}
template <class T>
void sortarray<T>:: insertionsort()
{
 T key;
 int i;
 for(int j=1; j<size; j++)
 {
 key=arr[j];
 i=j-1;
 while(i>=0 && arr[i]>key)
 {
 arr[i+1]=arr[i];
 i=i-1;
 }
 arr[i+1]=key;
 }
}
template<class T>
void sortarray<T>:: bubblesort()
{
 T temp;
 int i,j;
 char switched='T';
 for(i=0; i<size-1 && switched=='T'; i++)
 {
 switched='F';
 for(j=0; j<size-1-i; j++)
 {
 if(arr[j]>arr[j+1])
 {
 switched='T';
 temp=arr[j];
 arr[j]=arr[j+1];
 arr[j+1]=temp;
 }
 }
 }
}
template <class T>
void sortarray<T>:: selectionsort()
{
 T small,temp;
 int pos,i,j;
 for(int i=0; i<size; i++)
 {
     small=arr[i];
 pos=i;
 for(j=i+1; j<size; j++)
 {
 if(arr[j]<small)
 {
 small=arr[j];
 pos=j;
 }
 }
 temp=arr[i];
 arr[i]=arr[pos];
 arr[pos]=temp;
 }
}
template <class T>
void sortarray<T>:: display()
{
 cout<<"Elements of array are "<<endl;
 for(int i=0; i<size; i++)
 {
 cout<<arr[i]<<'\t';
 }
 cout<<endl;
}
int main()
{
 sortarray<int> s1;
 char ch='y';
 int choice;
 while(ch=='y'|| ch=='y')
 {
 cout<<"Main menu "<<endl;
 cout<<" 0.EXIT"<<endl;
 cout<<" 1.BUBBLE SORT"<<endl;
 cout<<" 2.INSERTION SORT"<<endl;
 cout<<" 3.SELECTION SORT"<<endl;
 cout<<"ENTER YOUR CHOICE BETWEEN[1-3],Press 0 to exit :"<<endl;;
 cin>>choice;
 switch(choice)
 {
     case 0 : exit(0);

 case 1: s1.input();
         cout<<"Before sorting \n";
         s1.display();
         s1.bubblesort();
         s1.display();
         break;

 case 2: s1.input();
         cout<<"Before sorting \n";
         s1.display();
         s1.insertionsort();
         s1.display();
          break;

 case 3: s1.input();
         cout<<"Before sorting \n";
         s1.display();
         s1.selectionsort();
         s1.display();
          break;
 }
 cout<<"DO YOU WANT TO CONTINUE (Y/N) : ";
 cin>>ch;
 }
}
