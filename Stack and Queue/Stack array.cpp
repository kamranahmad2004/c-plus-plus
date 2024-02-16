#include<iostream>
using namespace std;

int Size = 6;
int top = -1;
int* Stack = new int[Size];

int isEmpty()
{
    if(top == -1)
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
    if(top == Size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if(isFull())
    {
        cout<<"Stack is full, Data cannot be pushed "<<endl;
    }
    else
    {
        top++;
        Stack[top] = data;
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
        cout<<"Popped Data is : "<<Stack[top];
        top--;
        cout<<endl;
    }
}

void Top()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty "<<endl;
    }
    else
    {
        cout<<"Top Data is " <<Stack[top]<<endl;
    }
}
void Display()
{
    if(isEmpty())
    {
        cout<<"Stack is Empty "<<endl;
    }
    else
    {
        cout<<"Displaying Data "<<endl;
        for(int i=top; i>=0; i--)
        {
            cout<<"Data is : "<<Stack[i]<<endl;
        }
    }
}

int main()
{
    push(12);
    push(17);
    Display();
    pop();
    Display();
    Top();
}
