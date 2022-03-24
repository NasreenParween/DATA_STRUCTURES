#include<iostream>
using namespace std;

template<class T>
class node{
    public :
    T info;
    node *next;
    node(T x,node *n=NULL){
        info=x;
        next=n;
    }
};
template<class T1>
class queuetype{
    node<int> *f, *r;
    public:
    queuetype(){
        f=r=NULL;
    }
    int isempty();
    void enqueue(T1 x);
    T1 dequeue();
    void display();
    T1 rearmost();
    T1 frontmost();
    int count();

};

template<class T1> int queuetype<T1>::isempty(){
    if(f==NULL)
    return 1;
    else
    return -1;
}

template<class T1> void queuetype<T1>::enqueue(T1 x){
    node<int> *temp;
    temp=new node<int>(x);
    if(f==NULL){
        f=r=temp;
    }
    else{
        r->next=temp;
        r=temp;
    }
}

template<class T1> T1 queuetype<T1>::dequeue(){
    int x;
    x=f->info;
    if(f==r){
        delete f;
        f=r=NULL;
    }
    else{
        node<int> *temp;
        temp=f;
        f=f->next;
        delete temp;
    }
    return x;
}

template<class T1> void queuetype<T1>::display(){
    if(f==NULL){
        cout<<"Queue is empty \n";
    }
    else{
        node<int> *temp;
        for(temp=f;temp!=NULL;temp=temp->next){
            cout<<temp->info<<" ";
        }
    }
}

template<class T1> T1 queuetype<T1>::rearmost(){
    return r->info;

}

template<class T1> T1 queuetype<T1>::frontmost(){
 return f->info;
}

template<class T1> int queuetype<T1>:: count(){
 int c1=0;
 node<int>  *ptr;
if(f== NULL){
 return 0;}
 else
 {
 for(ptr=f; ptr!=NULL; ptr=ptr->next)
 c1++;
 return c1;
 }
}

int main(){
queuetype<int> q1;
 int e,a,d,choice,c1,top,last;

 node<int> *temp;

 do{
cout<<"Main Menu \n 0.Exit \n 1. Addition \n 2. Deletion \n 3. Check if queue is empty  \n 4. Count the elements \n  5.Rearmost element \n 6.Frontmost element \n 7.Display the queue \n   ENTER YOUR CHOICE(1-7). PRESS 0 TO EXIT \n \n";

    cin>>choice;

    switch(choice){
        case 0:
        break;
        case 1:
       cout<<"enter an element \n";
       cin>>a;
     q1.enqueue(a);
     break;
     case 2 :
     e=q1.isempty();
     if(e==1){
         cout<<"Queue is empty \n";
     }
     else{
         d=q1.dequeue();
         cout<<d<<" has been deleted \n";
     }
     break;

     case 3:
     e=q1.isempty();
     if(e==1){
         cout<<"Queue is empty \n";
     }
     else{
         cout<<"Queue is not empty \n";
     }
     break;

     case 4 :
     c1=q1.count();
     cout<<"Total elements in the queue are : "<<c1<<endl;
break;

case 5 :
e=q1.isempty();
if(e==1){
    cout<<"Queue is empty \n";
}
else{
    last=q1.rearmost();
    cout<<last<<" is the rearmost element \n";
}
break;
case 6 :
e=q1.isempty();
if(e==1){
    cout<<"Queue is empty \n";
}
else{
    top=q1.frontmost();
    cout<<top<<" is the frontmost element \n";
}
break;

case 7 :
    q1.display();
    break;

default :
cout<<"Enter a valid choice \n";
break;
    }

 }while(choice!=0);

 return 0;
}
