#include<iostream>
using namespace std;

int Size = 6;
int* Queue = new int [Size];
int Front = -1;

int isEmpty()
{
    if(Front == -1)
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
    if(Front == Size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int num)
{
    if(isFull())
    {
        cout<<"Queue is full, Data can't be enqueue "<<endl;
    }
    else
    {
        Front++;
        Queue[Front] = num;
    }
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"List is Empty, Data cannot be Dequeue "<<endl;
    }
    else
    {
        for(int i=0; i<=Front; i++)
        {
            Queue[i] = Queue[i+1];
        }
        Front--;
    }
}

void Front_Queue()
{
    if(isEmpty())
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        cout<<"\nFront Queue Element is : "<<Queue[0]<<endl;
    }
}

void Display()
{
    if(isEmpty())
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        cout<<"Displaying Data "<<endl;
        for(int i=0; i<=Front; i++)
        {
            cout<<"Data is : "<<Queue[i]<<endl;
        }
    }
}

int main()
{
    enqueue(15);
    enqueue(35);
    Display();
    Front_Queue();
    dequeue();
    Display();
    return 0;
}
