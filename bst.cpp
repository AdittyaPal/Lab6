#include <iostream>
using namespace std;
class Node//defines the structure of each Node of the tree
{
    public:
    int data;//stores the data
    Node* left;//pointer ti the next node on the left
    Node* right;//pointer to the next node on the right
    Node* previous;
    public:
    Node(int val)//parameterized constructor to assign the passed values
    {
        data=val;//data stoes the passed integer arguement
        left=NULL;//pointer to the next Node on the left NULL by deafult
        right=NULL;//pointer to the next Node on the right NULL by default
        previous=NULL;
    }//end of parametrized constructor
};//end of class Node
class BinarySearchTree
{
    private:
    Node* root;//data memeber pointing to the root of the tree
    public:
    BinarySearchTree()//default constructor
    {
        root=NULL;//assigns NULl to root
    }//end of default constructor
    void insert(int value)//function to call the method to insert a value into the tree
    {
        insert(root,value);//using root which is a private memeber
    }//end of the dummy function
    void insert(Node* current,int value)//function to insert a value into the tree
    {
        if(current==NULL)//if the subtree is empty
        root=new Node(value);//the new node is added to it
        else
        {
            if(current->data>value)//it is checked whether the new node should be placed to the left of the current node
            {
                if(current->left==NULL)//if there are no nodes to the left
                {
                    current->left=new Node(value);//the new node is inserted there
                    current->left->previous=current;
                }
                else
                insert(current->left,value);//the left subtree is traversed to place the new node
            }
            else//else it is placed to the right of the current node
            {
                if(current->right==NULL)//if there are no nodes to the right
                {
                    current->right=new Node(value);//the new node is inserted there
                    current->right->previous=current;
                }
                else
                insert(current->right,value);//the right subtree is traversed to place the new node
            }
        }
    }//end of the function to insert a node in the tree
    Node* search(int num)//function to call the method to insert a value into the tree
    {
        return search(root,num);//using root which is a private memeber
    }//end of the dummy function
    Node* search(Node* current,int num)//function to search if an element is present in the tree
    {
        if(current==NULL)//if the subtree is empty
        return current;//then the tree has been searched and element is not found
        else
        {
            if(current->data==num)//if the value to be search equals the value at the current node
            return current;//the address of the current node is returned
            else if(current->data>num)//if the element to be searched for is less than the value at the current node
            return search(current->left,num);//the left subtree is traversed to find the element
            else
            return search(current->right,num);//the right subtree is traversed to find the element
        }
    }//end of the function to search for an element in the tree
    Node* findMin(Node* current)//function to find the minimum of the given subtree
    {
        if(current->left!=NULL)//till a left node of the subtree is present
        return findMin(current->left);//it is traversed
        else
        return current;//the current node is the leftmost and returned
    }//end of the function to find the minimum of the given subtree
    void replaceAtParent(Node* A, Node* B)
    {
        if(A->previous->left==A)
        A->previous->left=B;
        else if(A->previous->right==A)
        A->previous->right=B;
        if(B!=NULL)
        B->previous=A->previous;
        A->previous=NULL;
    }
    void deleteNode(int value)//function to call the delete a node from the tree
    {
        Node* ptr=search(value);
        if(ptr==NULL)//if current is null the the end of the tree has been reached without encountering the value to be deleted
        cout<<"The value is not present in the tree.\n";
        else
        {
            if(ptr->left==NULL&&ptr->right==NULL)//if the node is a leaf
            {
                replaceAtParent(ptr,NULL);
                delete ptr;//the node is deleted
            }
            else if(ptr->left==NULL)//if the node has a right subtree
            {
                replaceAtParent(ptr,ptr->right);
                delete ptr;//the node is deleted
            }
            else if(ptr->right==NULL)//if the node has a left subtree
            {
                replaceAtParent(ptr,ptr->left);
                delete ptr;//the node is deleted
            }
            else//if the node has a right subtree and a left subtree
            {
                Node* temp=findMin(ptr->right);//pointer to the left subtree of the current node
                //cout<<temp->data<<endl;
                replaceAtParent(ptr,temp);
                //cout<<temp->previous->left->data<<endl;
                //cout<<temp->previous->right->data<<endl;
                temp->left=ptr->left;
                ptr->left->previous=temp;
                /*if(ptr->right==temp)
                {
                    temp->right=ptr->right->right;
                    ptr->right->right->previous=temp;
                }
                else
                {
                    temp->right=ptr->right;
                    ptr->right->previous=temp;
                }*/
                //cout<<ptr->left->data<<endl;
                //cout<<ptr->right->data<<endl;
                delete ptr;//the current node is deleted
            }
        }
    }
    void display()//function to call the method to display the tree horizontally
    {
        display(root,0);//using root which is a private memeber
        cout<<endl;
    }//end of the dummy function
    void display(Node* current,int space)//function to display the tree horizontally
    {
        if(current!=NULL)//if the end of the subtree has not been reached
        {
            display(current->right,++space);//the right subtree is displayed with an increased tab space
            cout<<endl;//a new line to print the current node value
            for(int i=1;i<space;i++)//for loop to print the correct number of
            cout<<"\t";//tab spaces
            cout<<current->data<<endl;//the value at the root of the current subtree is displayed
            display(current->left,space);//the left subtree is displayed
        }
    }//end of function to display the tree horizontally
    int count()
    {
        return count(root);
    }
    int count(Node* current)
    {
        if(current!=NULL)
        return (1+count(current->left)+count(current->right));
        else
        return 0;
    }
    /*int height()
    {
        return height(root);
    }
    int height(Node* current)
    {
        if(current==NULL)
        return 0;
        else 
        {
            if(height(current->left>current->right)
            return (1+height(current->left));
            else
            return (1+height(current->right));
        }
    }*/
};
int main()//main function
{
    BinarySearchTree b1;//binary search tree object is created
    int choice=0;
    int value=0;
    cout<<"Enter 1 till the user wants to input elements into the tree else 0.\n";
    do
    {
        cout<<"Enter your choice.\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the value to be inserted into the tree.\n";
            cin>>value;
            b1.insert(value);
        }
    }while(choice!=0);
    b1.display();
    cout<<"Enter a value to be deleted from the tree.\n";
    cin>>value;
    b1.deleteNode(value);
    b1.display();
}
