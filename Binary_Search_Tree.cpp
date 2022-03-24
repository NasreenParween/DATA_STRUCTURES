#include <iostream>
#include<conio.h>
using namespace std;
template<class T>
struct node
{
    T info;
    struct node<T>*left;
    struct node<T>*right;
     node()
    {
        info=0;
        left=right=NULL;
    }
};
template<class T>
class BST
{

public:
    struct node<T>*root;
    int lcount;
    int ncount;
    BST()
    {
        root = NULL;
        lcount=0;
        ncount=0;
    }
    void insert(node<T> *, node<T> *);
    void preorder(node<T>*);
    void inorder(node<T>*);
    void postorder(node<T>*);
    void display(node<T>*, int);
    T MaxHeight(node<T>*);
    void printLevelOrder(node<T>*);
    void printGivenLevel(node<T>*, int);
    void deleteByMerge(node<T>*& del);
     void FindDelete(T el);


};
template <class T>
void BST<T>::FindDelete(T el)
{
    node<T>* temp=root, *prev=NULL;
    while(temp!=NULL)
    {
        if(temp->info==el)
        {
            break;
        }
        prev=temp;
        if(el<temp->info)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    if(temp!=NULL && temp->info==el)
    {
        if(temp==root)
        {
            deleteByMerge(root);
        }
        else if(prev->left==temp)
        {
            deleteByMerge(prev->left);
        }
        else{
            deleteByMerge(prev->right);
        }
    }
    else if(root!= NULL)
    {
        cout<<"Element "<<el<<" not in the tree"<<endl;
    }
    else{
        cout<<"Tree is empty"<<endl;
    }
}

template<class T>
 void BST<T>::insert(node<T>* tree, node<T>* newnode )
{
   if (root == NULL)
	{
		root = newnode;
		return;
	}
	if (tree->info > newnode->info)
	{
		if (tree->left != NULL)
			insert(tree->left, newnode);
		else
			tree->left = newnode;
		return;
	}
	else
	{
		if (tree->right != NULL)
			insert(tree->right, newnode);
		else
			tree->right = newnode;
		return;
	}
}
template<class T>
void BST<T>::preorder(node<T>* ptr)
{
    if(root == NULL)
    {
        cout<<"Tree is Empty"<<endl;
        return;
    }
    if(ptr != NULL)
    {
        cout<<ptr->info<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
template<class T>
void BST<T>::inorder(node<T>* ptr)
{
    if(root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if(ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<" ";
        inorder(ptr->right);
    }
}
template<class T>
void BST<T>::postorder(node<T>* ptr)
{
    if(root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if(ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<" ";
    }
}
template<class T>
void BST<T>::display(node<T>* ptr, int Level)
{
    int i;
    if(ptr != NULL)
    {
        display(ptr->right, Level+1);
        cout<<endl;
        if(ptr == root)
            cout<<"Root-> : ";
        else
        {
            for(i=0; i<Level; i++)
                cout<<" ";
        }
        cout<<ptr->info;
        display(ptr->left, Level+1);
    }
}
template<class T>
T BST<T>::MaxHeight(node<T>* node)
{
    if(node == NULL)
        return 0;
    else
    {
        int LHeight = MaxHeight(node->left);
        int RHeight = MaxHeight(node->right);

        if(LHeight > RHeight)
            return(LHeight+1);
        else
            return(RHeight+1);
    }
}
template<class T>
 void BST<T>::printLevelOrder(node<T>* root)
{
    T h = MaxHeight(root);
    int i;
    for(i = 1; i <= h; i++)
        printGivenLevel(root, i);
}
template<class T>
void BST<T>::printGivenLevel(node<T>* , int Level)
{
    if(root == NULL)
        return;
    if(Level == 1)
        cout<<root->info<<" ";
    else if(Level > 1)
    {
        printGivenLevel(root->left, Level-1);
        printGivenLevel(root->right, Level-1);
    }
}
template <class T>
void BST<T>::deleteByMerge(node<T>*& del)
{
   node<T>* temp=del;
   if(del!=NULL)
    {
        if(!del->right)
        {
            del=del->left;
        }
        else if(del->left==NULL)
        {
            del=del->right;
        }
        else
        {
            temp=del->left;
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=del->right;
            temp=del;
            del=del->left;
        }
        delete temp;
    }
}

int main()
{
    BST<int> bst;
    int choice,h,del;
    char ch = 'y';
    node<int>*temp;
    while(ch=='y'||ch=='Y')
    {
        cout<<"--------------------"<<endl;
        cout<<" ..MAIN MENU.."<<endl;
         cout<<"--------------------"<<endl;
		cout<<"1. INSERT ELEMENTS "<<endl;
		cout<<"2. INORDER TRAVERSAL"<<endl;
		cout<<"3. PREORDER TRAVERSAL"<<endl;
		cout<<"4. POSTORDER TRAVERSAL"<<endl;
		cout<<"5. DISPLAY"<<endl;
		cout<<"6. MAXIMUM HEIGHT"<<endl;
		cout<<"7. LEVEL BY LEVEL TRAVERSAL "<<endl;
		cout<<"8. DELETE BY MERGING "<<endl;
		cout<<"9. Exit"<<endl;
		cout<<"ENTER YOUR CHOICE FROM 1 TO 8: ";
		cin>>choice;
		switch(choice){
			case 1: temp = new node<int>;
			        cout<<"Enter the number to be inserted : ";
			        cin>>temp->info;
			        bst.insert(bst.root,temp);
			        break;
            case 2:
                   cout<<"Inorder Traversal of BST : "<<endl;
                   bst.inorder(bst.root);
                   cout<<endl;
                   break;
            case 3:
                  cout<<"Preorder Traversal of BST"<<endl;
                  bst.preorder(bst.root);
                  cout<<endl;
                  break;
            case 4:
                  cout<<"Postorder Traversal of BST"<<endl;
                  bst.postorder(bst.root);
                  cout<<endl;
                  break;
            case 5:
                  cout<<"Display BST"<<endl;
                  bst.display(bst.root,1);
                  cout<<endl;
                  break;
            case 6: h = bst.MaxHeight(bst.root);
                   cout<<"Height = "<<h<<endl;
                   break;
            case 7: cout<<"Level by level traversal";
                bst.printLevelOrder(bst.root);
                cout<<endl;
                    break;
           case 8: cout<<"Enter the node you want to delete : ";
                   cin>>del;
                   bst.FindDelete(del);
                   cout<<"Tree after deletion : "<<endl;
                    bst.display(bst.root,1);
                    break;

            case 9: exit(1);
            default: cout<<"ERROR IN INPUT!!! ";
		}
		cout<<"Do u want to continue(Y/N): ";
		cin>>ch;
    }
    return 0;
}
