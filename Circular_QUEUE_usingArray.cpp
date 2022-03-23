#include<iostream>
using namespace std;

const int SIZE = 5;

template<class T>
class cqueue
{
 public:
 T cq[SIZE];
 int f,r;
 cqueue(){
 f=r=-1;
 }
 void insert(T);
 T remove();
 int isempty();
 int isfull();
 void display();
 void clear();
 T frontmost();
 T raremost();
 int count();
};
template<class T> void cqueue<T>::insert(T i)
{
 if(r==-1)
 {
 f=r=0;
 cq[r]=i;
 }
 else if(r==SIZE-1)
 {
 r=0;
 cq[r]=i;
 }
 else
 {
 r++;
 cq[r]=i;
 }
}
template<class T> T cqueue<T>::remove()
{
 T rem;
 if(f==r)
 {
 rem=cq[f];
 f=r=-1;
 }
 else if(f==SIZE-1)
 {
 rem=cq[f];
 f=0;
 }
 else{
 rem=cq[f];
 f++;
 }
 return rem;
}
template<class T> int cqueue<T>::isempty()
{
 if(f==-1 && r==-1)
 return 1;
 else
 return 0;
}
template<class T> int cqueue<T>::isfull()
{
 if(f==0 && r==SIZE-1 || r==f-1)
 return 1;
 else
 return 0;
}
template<class T> void cqueue<T>::display()
{
int i=0;
 if(f==-1)
 cout<<"Queue is empty"<<endl;

 if(r>=f)
 {
 cout<<"Contents of queue starting from front to rear end are: ";
 for(i=0;i<f;i++)
 cout<<" __ ";
 for(i=f;i<=r;i++)
 cout<<cq[i]<<" ";
 for( i=r+1;i<SIZE;i++)
 cout<<" __ ";
 }
 else
 {
 for( i=0;i<=r;i++)
 cout<<cq[i]<<"\t";
 for(;i<f;i++)
 cout<<"__"<<"\t";
 for(int i=f;i<SIZE;i++)
 cout<<cq[i]<<"\t";
 }
}
template<class T> void cqueue<T>::clear()
{
 f=r=-1;
}
template<class T> T cqueue<T>::frontmost()
{
 T res;
 res=cq[f];
 return res;
}
template<class T> T cqueue<T>::raremost()
{
 T res;
 res=cq[r];
 return res;
}
template<class T> int cqueue<T>::count()
{
 int c=0;
 if(f==-1)
 return 0;
 else if(f<=r)
 {
 for(int j=f;j<=r;j++)
 c++;
 return c;
 }

 else if(f>r)
 {
 for(int j=0;j<=r;j++)
 c++;
 return c;
 }
}
int main()
{
 cqueue<int> C;
 char ch;
 int choice,i,rem,empty,full,count,f,r;
 int val;
 do
 {
 cout<<" MAIN MENU "<<endl;
 cout<<"1. INSERT "<<endl;
 cout<<"2. REMOVE "<<endl;
 cout<<"3. CLEAR "<<endl;
 cout<<"4. CHECK is EMPTY "<<endl;
 cout<<"5. CHECK is FULL "<<endl;
 cout<<"6. FRONTMOST "<<endl;
 cout<<"7. RAREMOST "<<endl;
 cout<<"8. DISPLAY QUEUE "<<endl;
 cout<<"9. COUNT ELEMENTS "<<endl;
 cout<<" Enter your choice (1-9) : ";

 cin>>choice;
 switch(choice)
 {
 case 1: if(C.isfull()==1)
           cout<<" QUEUE IS FULL !! INSERTION NOT POSSIBLE: "<<endl;
           else
          {
              cout<<"Input for Insert Operation :"<<endl;
              cin>>val;
              C.insert(val);
          }
         C.display();
           break;
 case 2: if(C.isempty()==1)
          cout<<" UNDERFLOW !!! "<<endl;
        else
        C.remove();
        C.display();
        break;
case 3: C.clear();
        break;
case 4: if (C.isempty()==1)
        cout<<" Queue is Empty"<<endl;
        else
        cout<<" Queue is not Empty"<<endl;;
         break;
 case 5: if (C.isfull())
         cout<<" Queue is Full"<<endl;
         else
          cout <<" Queue is not Full"<<endl;
         break;
case 6: if(C.isempty()==1)
        cout<<" QUEUE IS EMPTY !!! "<<endl;
        else
       {
        cout<<" FRONTMOST ELEMENT : "<<endl;
        cout<<C.frontmost();
       }
        break;
case 7: if(C.isempty()==1)
        cout<<" QUEUE IS EMPTY!!! "<<endl;
        else
       {
        cout<<" RAREMOST ELEMENT : "<<endl;
        cout<<C.raremost();
        }
        break;
 case 8: C.display();
         break;
case 9: cout<<C.count();
        break;
default: cout<<" INVALID CHOICE!!!"<<endl;
         break;
 }
       cout<<"\n To Continue press (y/n) : ";
       cin>>ch;
 }    while(ch=='y' || ch=='Y');
    return 0;
}
