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
    void replaceAtParent(Node* A, Node* B)//function to replace A with B at the parent of A
    {
	if(A!=this->root)//if A is not the root of the tree
	{
	    if(A->previous->left==A)//if A is the left child
            A->previous->left=B;//then the left pointer of the parent of A now points to B
            else if(A->previous->right==A)//else if A is the right child
            A->previous->right=B;//then the right pointer of the parent of A now points to B
            if(B!=NULL)//if B is not NULL
            B->previous=A->previous;//the parent of B is the parent of A
            A->previous=NULL;//A is removed from the tree
	}
	else//if A is the root of the tree
	this->root=B;//the root of the tree is upadted to B
    }//end of the function to replace A with B at the parent of A
    void deleteNode(int value)//function to delete a node from the tree
    {
        Node* ptr=search(value);//pointer to the node to be deleted
        if(ptr==NULL)//if current is null the the end of the tree has been reached without encountering the value to be deleted
        cout<<"The value is not present in the tree.\n";
        else
        {
	    Node* temp=NULL;//temporary pointer to point to the node to replace the deleted node
	    if(ptr->left!=NULL&&ptr->right!=NULL)//if the node has a right subtree and a left subtree
            {
                temp=findMin(ptr->right);//the minimum element in the right subtree of the node to de deleted is found and temp points to it
                replaceAtParent(ptr,temp);//temp replaces the node to be deleted
                temp->left=ptr->left;//the left pointer of temp points to the left subtree of the deleted node
                ptr->left->previous=temp;//the parent of the left subtree of the deleted node is updated to temp
                if(ptr->right!=temp)//if the node on the right of the deleted node does not replace it, the pointers is updated
                {
                    temp->right=ptr->right;//the right pointer of temp points to the right subtree of the deleted node
                    ptr->right->previous=temp;//the parent of the right subtree of the deleted node is updated to temp
                }//else it would lead to a pointer pointing to itself
            }
            else
	    {
		if(ptr->left==NULL&&ptr->right==NULL);//if the node is a leaf
            	else if(ptr->left==NULL)//if the node has a right subtree
            	temp=ptr->right;//the node to replace the deleted node is its right subtree
            	else if(ptr->right==NULL)//if the node has a left subtree
           	temp=ptr->left;//the node to replace the deleted node is its left subtree
		replaceAtParent(ptr,temp);//temp replaces the node to be deleted
	    }
	     delete ptr;//ptr is deleted from the heap
		
        }
    }//end of the function to delete a node from the tree
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
};
/*int main()//main function
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
}*/
int main()
{    
    BinarySearchTree bst1;
    bst1.insert(4);
    bst1.insert(2);
    bst1.insert(3);
    bst1.insert(1);
    bst1.insert(6);
    bst1.insert(5);
    bst1.insert(7);
    bst1.insert(8);
    bst1.display();
    if(bst1.search(3)!=NULL)
    cout<<endl<<bst1.search(3)->data<<endl;
    bst1.display();
    bst1.deleteNode(5);
    bst1.display();
    bst1.deleteNode(6);
    bst1.display();
    cout<<"Deleting 2"<<endl;
    bst1.deleteNode(2);
    bst1.display();
    cout<<"Deleting 4"<<endl;
    bst1.deleteNode(4);
    cout<<"4 deleted"<<endl;
    bst1.display();
    bst1.deleteNode(7);
    bst1.display();
    bst1.deleteNode(8);
    bst1.display();
    bst1.deleteNode(3);
    bst1.display();
    bst1.deleteNode(1);
    bst1.display();
    bst1.deleteNode(1);
    bst1.display();
}
