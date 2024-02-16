#include<iostream>
using namespace std;

struct List
{
    int data;
    List* next;
};
int Count = 0;
int Size = 6;
List* top = NULL;

int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if(Count == Size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push()
{
    if(isFull())
    {
        cout<<"Stack is full, Data can't be pushed on stack "<<endl;
    }
    else
    {
        List* node = new List;
        cout<<"Enter Data : ";
        cin>>node->data;
        node->next = NULL;
        if(top == NULL)
        {
            top = node;
            Count++;
        }
        else
        {
            node->next = top;
            top = node;
            Count++;
        }
    }
}
void pop()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty "<<endl;
    }
    else
    {
        top = top->next;
        Count--;
    }
}

void Top()
{
    if(isEmpty())
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        cout<<"\nTop Data of Stack is : "<<top->data;
        cout<<endl;
    }
}
void Display()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty :"<<endl;
    }
    else
    {
        cout<<"\nDisplay Data "<<endl;
        List* temp = top;
        while(temp)
        {
            cout<<"Data is : "<<temp->data<<endl;
            temp = temp->next;
        }
    }
}
int main()
{
    push();
    push();
    push();
    Display();
    pop();
    Display();
    Top();

}
