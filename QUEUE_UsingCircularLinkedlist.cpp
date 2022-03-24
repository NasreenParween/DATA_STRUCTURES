#include <iostream>
#include<stdio.h>
using namespace std;
template<class T>
class node
{
public :
    int info;
    node<T>* next;
    node(int x, node<T>*n=NULL)
    {
        info=x;
        next=n;
    }
};
template<class T>
class queuetype
{

    node<T>*f,*r;
public:
    node<T>*next;
    queuetype()
    {

        f=r=NULL;
    }
    void enqueue(T x);
    T dequeue();
    T isempty();
    T counts();
    void clr();
    void display();
};template<class T>
void queuetype<T>::enqueue(T x)
{
    node<T> *temp;
    //T*next;
    temp=new node<T>(x);
    if(f==NULL)
    {
        f=r=temp;
        return;
    }
    else
    {
        r->next=temp;
        r=temp;
    }
}
template<class T>
T queuetype<T>::dequeue()
{
    int x;
    x=f->info;
    if(f==r)
    {
        delete f;
        f=r=NULL;
    }
    else{
        node<T>*temp;
        temp=f;
        f=f->next;
        delete temp;
    }return x;

}
template<class T>
T queuetype<T>::isempty()
{
   if(f==NULL)
    return 1;
   else
    return -1;
}
template<class T>
T queuetype<T>::counts()
{
    int c=0;
    node<T>*temp;
  for(temp=f; temp!=NULL; temp=temp->next)
  {
      c++;
  }

  cout<<"Number of nodes :"<<c<<endl;
}
template<class T>
void queuetype<T>::clr()
{
    node<T>*temp;
    for(temp=f;temp!=NULL;temp=f)
    {
        delete temp;
        f=f->next;
    }
}
template<class T>
void queuetype<T>::display()
{
    if(f==NULL)
    {
        cout<<"Queue is empty,Nothing to display";
    }
    else
    {
        cout<<"Contents of queue are:"<<endl;
        node<T>* temp;
        for(temp=f; temp!=NULL; temp=temp->next)
        {
            cout<<temp->info<<"\n";
        }
    }
}

int main()
{
    queuetype<int> q1;
    int f,e,a,d,choice;
    //T*temp;
    char c='y';
    while(c=='y'|| c=='y')
    {
        cout<<"MAIN MENU"<<endl;
        cout<<"1. TO ENQUEUE"<<endl;
        cout<<"2. TO DEQUEUE"<<endl;
        cout<<"3. TO CHECK WHETHER QUEUE IS EMPTY"<<endl;
        cout<<"4. TO COUNT ELEMENTS"<<endl;
        cout<<"5. TO CLEAR THE QUEUE "<<endl;
        cout<<"6. TO DISPLAY THE ELEMENT OF QUEUE"<<endl;
        cout<<"ENTER YOUR CHOICE [1-6]"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<" Enter the elements :"<<endl;
                    cin>>a;
                    q1.enqueue(a);
                    q1.display();
                    break;
            case 2: e=q1.isempty();
                    if(e==1)
                        cout<<"Queue is empty :"<<endl;
                    else
                    {
                        d=q1.dequeue();
                        cout<<d<<" Element has been deleted :"<<endl;
                        q1.display();
                    }
                    break;
            case 3: e=q1.isempty();
                    if(e==1)
                        cout<<"Queue is empty"<<endl;
                    else
                        cout<<"Queue is not empty"<<endl;
                    break;
            case 4: q1.counts();
                   q1.display();
                   break;
            case 5: q1.clr();
                    cout<<"Queue has been cleared"<<endl;
                    break;
            case 6: q1.display();
                   break;
            default : cout<<"ERROR IN INPUT"<<endl;
        }
        cout<<"DO YOU WANT TO CONTINUE (y/n)"<<endl;
        cin>>c;

    }
    return 0;
}
