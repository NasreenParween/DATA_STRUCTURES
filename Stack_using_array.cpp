#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int MAX = 7;
template <typename T>
class stackclass
{
    T s[MAX];
    int top;
    public:
    void push(T k);
    T pop();
    int isempty();
    int isfull();
    void display();
    stackclass() ;
};

template <class T> stackclass<T>::stackclass()
{
     top = -1;
      }

template <class T> void stackclass<T>::push(T k)
{
    top ++;
    s[top] = k;
}

template <class T> T stackclass<T> :: pop()
{
    T del = s[top];
    top--;
    return del;
}

template <class T> int stackclass<T> :: isempty()
{
    if(top == -1)
      return 1;
    else
      return -1;
}

template <class T> int stackclass<T> :: isfull()
{
    if(top == MAX-1)
      return 1;
    else
      return -1;
}

template <class T> void stackclass<T> ::display()
{
    cout<<"\n Contents of stack are : ";
    for (int i = top; i >=0 ; --i)
        cout<<"\n"<<s[i];
}
int main()
{
    stackclass<int> int_stack;
    stackclass<string> char_stack;
    int choice, to_push,c;
    string pushc;
    cout<<"\n 1)INTEGER STACK OR 2)CHARACTER: ";
    cin>>c;

    if(c == 1)
    {
        do {
        cout<<"\n 1. PUSH";
        cout<<"\n 2. POP";
        cout<<"\n 3. IS EMPTY";
        cout<<"\n 4. IS FULL";
        cout<<"\n 5. DISPLAY";
        cout<<"\n 6. Exit";
        cout<<"\n Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:

            if(int_stack.isfull() == 1)
                {

            cout<<"\n Stack full, can't push.";
            }
            else
            {
                cout<<"\n Enter element you want to push: ";
                cin>>to_push;
                int_stack.push(to_push);
            }
            break;
        case 2:

            if(int_stack.isempty() == 1)
                cout<<"\n Stack empty, can't pop.";
            else
            cout<<"Popped: "<<int_stack.pop();
            break;
        case 3:

            if(int_stack.isempty() == 1)
                cout<<"\n Stack empty!";
            else
            cout<<"\n Stack NOT empty!";
            break;
        case 4:

            if(int_stack.isfull() == 1)
                cout<<"\n Stack full!";
            else
            cout<<"\n Stack NOT full!";
            break;
        case 5:
            int_stack.display();
            break;

        default: cout<<"Error in output";
            break;
        }}while(choice != 6);
    }

    else if (c == 2)
    {
      do {

         cout<<"\n 1. PUSH";
        cout<<"\n 2. POP";
        cout<<"\n 3. IS EMPTY";
        cout<<"\n 4. IS FULL";
        cout<<"\n 5. DISPLAY";
        cout<<"\n 6. Exit";
        cout<<"\n Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:

            if(char_stack.isfull() == 1)
                cout<<"\n Stack full, can't push.";
            else
            {
                cout<<"\n Enter element you want to push: ";
                cin>>pushc;
                char_stack.push(pushc);
            }
            break;
        case 2:

            if(char_stack.isempty() == 1)
                cout<<"\n Stack empty, can't pop.";
            else
            cout<<"Popped: "<<char_stack.pop();
            break;
        case 3:

            if(char_stack.isempty() == 1)
                cout<<"\n Stack empty!";
            else  cout<<"\n Stack NOT empty!";
            break;
        case 4:

            if(char_stack.isfull() == 1)
            cout<<"\n Stack full!";
            else
            cout<<"\n Stack NOT full!";
            break;
        case 5:
            char_stack.display();
            break;

        default:cout<<"Error in output";
            break;
        }
        }
        while(choice != 6);
    }
    return 0;
}
