#include<iostream>
using namespace std;

struct List
{
    int data;
    List* next;
};
List* Front = NULL;
int Count, Size = 5;

int isEmpty()
{
    if(Front == NULL)
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
    if(Count == Size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue()
{
    if(isFull())
    {
        cout<<"List is Full, Data can't be enqueued "<<endl;
    }
    else
    {
        List* node =  new List;
        cout<<"Enter Data : ";
        cin>>node->data;
        node->next = NULL;

        if(Front == NULL || node->data > Front->data)
        {
            node-> next = Front;
            Front = node;
        }
        else
        {
            List* temp = Front;
            while(temp->next != NULL || temp->next->data > node->data)
            {
                temp = temp->next;

            }
            node->next = temp->next;
            temp->next = node;
        }
        Count++;
    }
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"List is Empty, Data can't be Dequeue "<<endl;
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
        cout<<"Front Queue is : "<<Front->data;
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
        List* temp = Front;
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
    enqueue();
    Display();
    return 0;
}
