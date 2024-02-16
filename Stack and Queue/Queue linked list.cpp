#include<iostream>
using namespace std;

struct List
{
    int data;
    List* next;
};
List* Front = NULL;
int Count, Size = 5;

bool isEmpty()
{
    if(Front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if(Count == Size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue()
{
    if(isFull())
    {
        cout<<"List is full, Data can't be enqueued "<<endl;
    }
    else
    {
        List* node = new List;
        cout<<"Enter Data : ";
        cin>>node->data;
        node->next = NULL;

        if(Front == NULL)
        {
            Front = node;
            Count++;
        }
        else
        {
            List* temp = Front;
            while(temp)
            {
                if(temp->next == NULL)
                {
                    temp->next = node;
                    Count++;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
    }
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"List is Empty, Data can't be Dequeued "<<endl;
    }
    else
    {
        Front = Front->next;
        Count--;
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
        cout<<"Front Queue Element is : "<<Front->data<<endl;
    }
}

void Display()
{
    if(isEmpty())
    {
        cout<<"List is Empty " <<endl;
    }
    else
    {
        List* temp = Front;
        cout<<"\nDisplaying Data : "<<endl;
        while(temp)
        {
            cout<<"Data is : "<<temp->data<<endl;
            temp = temp->next;
        }
    }
}

int main()
{
    enqueue();
    enqueue();
    Display();
    Front_Queue();
    dequeue();
    Display();
}
