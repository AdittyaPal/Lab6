#include <iostream>
using namespace std;
class Node//defines the structure of each Node of the tree
{
    public:
    int data;//stores the data
    Node* left;//pointer ti the next node on the left
    Node* right;//pointer to the next node on the right
    public:
    Node(int val)//parameterized constructor to assign the passed values
    {
        data=val;//data stoes the passed integer arguement
        left=NULL;//pointer to the next Node on the left NULL by deafult
        right=NULL;//pointer to the next Node on the right NULL by default
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
                current->left=new Node(value);//the new node is inserted there
                else
                insert(current->left,value);//the left subtree is traversed to place the new node
            }
            else//else it is placed to the right of the current node
            {
                if(current->right==NULL)//if there are no nodes to the right
                current->right=new Node(value);//the new node is inserted there
                else
                insert(current->right,value);//the right subtree is traversed to place the new node
            }
        }
    }//end of the function to insert a node in the tree
    Node* findMin(Node* current)//function to find the minimum of the given subtree
    {
        if(current->left!=NULL)//till a left node of the subtree is present
        return findMin(current->left);//it is traversed
        else
        return current;//the current node is the leftmost and returned
    }//end of the function to find the minimum of the given subtree
    void delet(int value)//function to call the delete a node from the tree
    {
        root=delet(root,value);//using a private member root
    }//end of the dummy function
    Node* delet(Node* current,int value)//function to delete a node from the tree
    {
        if(current==NULL)//if current is null the the end of the tree has been reached without encountering the value to be deleted
        {
            cout<<"The value is not present in the tree.\n";
            return current;//the recursion stops
        }
        else if(current->data==value)//else if the node to be deleted is reached
        {
            Node* temp=NULL;
            if(current->left==NULL&&current->right==NULL);//if the node is a leaf
            else if(current->left==NULL)//if the node has a right subtree
            temp=current->right;//temp points to the right subtree of the current node
            else if(current->right==NULL)//if the node has a left subtree
            temp=current->left;//temp points to the left subtree of the current node
            else//if the node has a right subtree and a left subtree
            {
                 findMin(current->right)->left=current->left;//the minimum of the right subtree is moved to the current position with its left subtree being the current left subtree
                 temp=current->right;//temp points to the right subtree of the current node
            }
        delete current;//the node is deleted
        return temp;//the node pointed to by temp is attached to the tree
        }
        else if(value<current->data)//if the value to the deleted is lesser than the value at the current node
        current->left=delet(current->left,value);//the node to be deleted might be on the left subtree
        else//if the value to the deleted is greater than the value at the current node
        current->right=delet(current->right,value);//the node to be deleted might be on the left subtree
        return current;//the current node is returned to be attached to the tree
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
    b1.delet(value);
    b1.display();
}*/
int main(){
   
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
    bst1.delet(5);
    bst1.display();
    bst1.delet(6);
    bst1.display();
    cout << "Deleting 2" << endl;
    bst1.delet(2);
    bst1.display();
    bst1.delet(4);
    bst1.display();
    bst1.delet(7);
    bst1.display();
    bst1.delet(8);
    bst1.display();
    bst1.delet(3);
    bst1.display();
    bst1.delet(1);
    bst1.display();
    bst1.delet(1);
    bst1.display();

}
