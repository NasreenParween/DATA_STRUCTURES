#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};
void printll(const node *head)
{
   while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node *createll(int n){
int x;
node *head=NULL;
node *tail=NULL;
cout<<"Enter the elements :"<<endl;
for(int i=0;i<n;i++)
{
cin>>x;
    node *n=new node(x);
        if(head==NULL)
        {
            head=n;
            tail=n;
        }
    else
    {
        tail->next=n;
        tail=tail->next;
    }
}
return head;
}
void removeDuplicates(node *start)
{
    node *ptr1, *ptr2, *dup;
    ptr1 = start;
    /* Pick elements one by one */
    cout<<"After removed duplicates, elements are :"<<endl;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else //This is tricky
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
int main()
{
    int n;
    cout<<"How many elements you want to enter: "<<endl;
    cin>>n;
    node *head=createll(n);
   removeDuplicates(head);
    printll(head);
}
