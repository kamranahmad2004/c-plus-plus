#include<iostream>
using namespace std;
struct List
{
    int data;
    List* next;
    List* prev;
};
List* Head = NULL;
List* Tail = NULL;

void Insert_Data()
{
    List* node = new List;
    cout<<"Enter Data : ";
    cin>>node->data;
    node->next = node->prev = NULL;
    if(Head == NULL)
    {
        Head = node;
        node->next = Head;
    }

    else
    {
        List* temp = Head;
        while(temp)  // temp!= NULL
        {
            if(temp->next == Head)
            {
                temp->next = node;
                node->prev = temp;
                Tail = node;

                Tail->next = Head;
                Head->prev = Tail;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

void Display_Data()
{
    if(Head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        List* temp = Head;
        cout<<"\nDisplaying Data "<<endl;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        while(temp!= Head);
    }
}

void Display_Data_Backwards()
{
    if(Head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        List* temp = Tail;
        cout<<"\n\nDisplaying Data from Backwards "<<endl;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        while(temp!= Tail);
    }
}
int main()
{
    int num;
    cout<<"Enter how many nodes data do you want to insert : ";
    cin>>num;
    for(int i=0; i<num; i++)
    {
        Insert_Data();
    }
    cout<<"Data is Inserted Successfully "<<endl;
    Display_Data();
    Display_Data_Backwards();
    return 0;
}



