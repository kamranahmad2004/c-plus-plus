#include <iostream>
using namespace std;
struct Tree
{
    int data;
    Tree* left;
    Tree* right;
};
Tree* root = NULL;

void Insert_Data()
{
    Tree* node = new Tree;
    node->left = node->right = NULL;
    cout<<"Enter Data : ";
    cin>>node->data;
    if(root == NULL)
    {
        root = node;
    }
    else
    {
        Tree* temp = root;
        while(temp)
        {
            if(node->data < temp->data)
            {
                if(temp->left == NULL)
                {
                    temp->left = node;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if(node->data > temp->data)
            {
                if(temp->right == NULL)
                {
                    temp->right = node;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else
            {
                cout<<"Duplicate number "<<endl;
            }
        }
    }
}

void In_Order(Tree* temp)
{
    if(temp == NULL)
    {

    }
    else
    {
        In_Order(temp->left);
        cout<<temp->data<<" ";
        In_Order(temp->right);
    }
}

void Pre_Order(Tree* temp)
{
    if(temp == NULL)
    {

    }
    else
    {
        cout<<temp->data<<" ";
        Pre_Order(temp->left);
        Pre_Order(temp->right);
    }
}

void Post_Order(Tree* temp)
{
    if(temp == NULL)
    {

    }
    else
    {
        Post_Order(temp->left);
        Post_Order(temp->right);
        cout<<temp->data<<" ";
    }
}

struct List
{
    int data;
    List* next;
};
List* Front = NULL;

void Enqueue(int val)
{
    List* node = new List;
    node->data = val;
    node->next = NULL;

    if(Front == NULL)
    {
        Front = node;
    }
    else
    {
        List* temp = Front;
        while(temp)
        {
            if(temp->next == NULL)
            {
                temp->next = node;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

void Search_Node(int val)
{
    Tree* temp = root;
    while(temp)
    {
        if(temp->data == val)
        {
            if(temp->left != NULL)
            {
                Enqueue(temp->left->data);
            }
            if(temp->right != NULL)
            {
                Enqueue(temp->right->data);
            }
            break;
        }
        else if(val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
}

void Level_Order(Tree* temp)
{
    if(temp == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        Enqueue(temp->data);
        while(Front)
        {
            cout<<Front->data<<" ";
            Search_Node(Front->data);
            Front = Front->next;
        }
    }
}

int min_value()
{
    if(root == NULL)
    {
        return 1;
    }
    else
    {
        Tree* temp = root;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }
}

int max_value()
{
    if(root == NULL)
    {
        return 1;
    }
    else
    {
        Tree* temp = root;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->data;
    }
}

int main()
{
    int num;
    cout<<"Enter how many elements do you want to insert in Tree : ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        Insert_Data();
    }
    cout<<"\nDisplaying Data in In Order method "<<endl;
    In_Order(root);
    cout<<"\n\nDisplaying Data in Pre Order method "<<endl;
    Pre_Order(root);
    cout<<"\n\nDisplaying Data in Post Order method "<<endl;
    Post_Order(root);
    cout<<endl;
    cout<<"\nDisplaying Data in Level Order "<<endl;
    Level_Order(root);
    cout<<endl;
    //cout<<"Min value in Tree is : "<<min_value();
    //cout<<"\nMax value in Tree is : "<<max_value();
    return 0;
}
