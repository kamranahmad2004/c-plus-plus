#include<iostream>
using namespace std;
struct Tree
{
    int data;
    Tree* left;
    Tree* right;
};
Tree* root = NULL;
void insert_node()
{
    Tree* node = new Tree;
    cout<<"Enter Data : ";
    cin>>node->data;
    node->left = node->right = NULL;
    if(root == NULL)
    {
        root = node;
    }
    else
    {
        Tree* temp = root;
        while(temp!= NULL)
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
                cout<<"Duplicate Data "<<endl;
            }
        }
    }
}

void In_order(Tree* temp)
{
    if(temp == NULL)
    {
        //  cout<<"Empty Data "<<endl;
    }
    else
    {
        In_order(temp->left);
        cout<<temp->data<<" ";
        In_order(temp->right);
    }
}

void Pre_order(Tree* temp)
{
    if(temp == NULL)
    {
        //cout<<"Empty Data "<<endl;
    }
    else
    {
        cout<<temp->data<<" ";
        Pre_order(temp->left);
        Pre_order(temp->right);
    }
}

void post_order(Tree* temp)
{
    if(temp == NULL)
    {

    }
    else
    {
        post_order(temp->left);
        post_order(temp->right);
        cout<<temp->data<<" ";
    }
}
int main()
{
    int num;
    cout<<"Enter how many elements do you want to insert : ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        insert_node();
    }
    cout<<"\nData Displayed in In Order method"<<endl;
    In_order(root);
    cout<<"\n\nData Displayed in Pre Order method"<<endl;
    Pre_order(root);
    cout<<"\n\nData Displayed in Post Order method"<<endl;
    post_order(root);
    cout<<endl;
    return 0;
}




