#include <iostream>
using namespace std;
struct List
{
    int id;
    string name;
    double salary;
    List* next;
    List* prev;
};

List* Head = NULL;
List* Tail = NULL;

void Insert_Data()
{
    List* node = new List;
    cout<<"Enter Employee's Id : ";
    cin>>node->id;
    cout<<"Enter Employee's Name : ";
    cin.ignore();
    getline(cin, node->name);
    cout<<"Enter Employee's Salary : ";
    cin>>node->salary;
    node->next = node->prev = NULL;
    if(Head == NULL)
    {
        Head = node;
        Tail = node;
    }
    else
    {
        List* temp = Head;
        while(temp)
        {
            if(temp->next == NULL)
            {
                temp->next = node;
                node->prev = temp;
                Tail = node;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    cout<<"Data is Inserted Successfully "<<endl;
}

void Update_Data()
{
    if(Head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        int Id;
        cout<<"Enter Specific Employee's Id for Update : ";
        cin>>Id;
        List* temp = Head;
        while(temp) // temp != NULL
        {
            if(temp->id == Id)
            {
                cout<<"\nData is Found "<<endl;
                cout<<"Enter Employee's Id for Update : ";
                cin>>temp->id;
                cout<<"Enter Employee's Name for Update : ";
                cin.ignore();
                getline(cin, temp->name);
                cout<<"Enter Employee's Salary for Update : ";
                cin>>temp->salary;
                cout<<"\nYour Data is Updated Successfully "<<endl;
                break;
            }
            else if(temp->next == NULL)
            {
                cout<<"Data does not exist "<<endl;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

void Search_Data()
{
    if(Head == NULL)
    {
        cout<<"List is Empty ";
    }
    else
    {
        int data;
        cout<<"Enter Specific Employee's Id for Search Data : ";
        cin>>data;
        List* temp = Head;
        while(temp)
        {
            if(temp->id == data)
            {
                cout<<"Your Searching Data is Found "<<endl;
                cout<<"Employee's Id is : "<<temp->id<<endl;
                cout<<"Employee's Name is : "<<temp->name<<endl;
                cout<<"Employee's Salary is : "<<temp->salary<<endl;
                break;
            }
            else if(temp->next == NULL)
            {
                cout<<"Data does not exist "<<endl;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
}

void Delete_Data()
{
    if(Head == NULL)
    {
        cout<<"List is empty "<<endl;
    }
    else
    {
        int data;
        cout<<"Enter Id for Specific Employee : ";
        cin>>data;
        if(Head->id == data && Head->next == NULL)
        {
            Head = NULL;
        }
        else if(Head->id == data && Head->next != NULL)
        {
            Head = Head->next;
            Head->prev = NULL;
        }
        else
        {
            List* temp = Head;

            while(temp != NULL)
            {
                if(temp->next->id == data && temp->next != Tail)
                {
                    temp->next = temp->next->next;
                    temp->next->prev = temp ;
                    break;
                }
                else if(temp->next->id == data && temp->next == Tail)
                {
                    temp->next = NULL;
                    Tail->prev = NULL;
                    Tail = temp;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
    }
    cout<<"Node is Deleted Successfully "<<endl;
}
void Display_Data()
{
    if(Head == NULL)
    {
        cout<<"List is Empty ";
    }
    else
    {
        cout<<"Displaying Data of Employee(s) "<<endl;
        List* temp = Head;
        while(temp)
        {
            cout<<"\nEmployee's Id is : "<<temp->id<<endl;
            cout<<"Employee's Name is : "<<temp->name<<endl;
            cout<<"Employee's Salary is : "<<temp->salary<<endl;
            temp = temp->next;
        }
    }
}

void Display_Backwards()
{
    if(Head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        cout<<"Displaying Data in Backwards "<<endl;
        List* temp = Tail;
        while(temp)
        {
            cout<<"\nEmployee's Id is : "<<temp->id<<endl;
            cout<<"Employee's Name is : "<<temp->name<<endl;
            cout<<"Employee's Salary is : "<<temp->salary<<endl;
            temp = temp->prev;
        }
    }
}
int main()
{
    system("Color E4");
    cout<<"\n     -------------  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  --------------- "<<endl;
    int choice;
    do
    {
        cout<<"\n:::::::::::: Main Menu :::::::::::::\n\n";
        cout<<" [1] Insert Data "<<endl;
        cout<<" [2] Update Data "<<endl;
        cout<<" [3] Search Data "<<endl;
        cout<<" [4] Delete Data "<<endl;
        cout<<" [5] Display all Data "<<endl;
        cout<<" [6] Display Data in Backwards "<<endl;
        cout<<" [7] Exit "<<endl;
        cout<<"\nEnter your choice from List (1-7) : ";
        cin>>choice;
        cout<<endl;
        if(choice < 1 || choice > 7)
        {
            while(choice < 1 || choice > 7)
            {
                cout<<"Please enter valid number from (1 - 7) according to your choice : "<<endl;
                cout<<"Enter your choice : ";
                cin>>choice;
            }
        }
        switch(choice)
        {
        case 1:
        {
            int num;
            cout<<"Enter how many nodes do you want to insert : ";
            cin>>num;
            for(int i=0; i<num; i++)
            {
                cout<<"\nEnter Employee's Data for no "<<i + 1<<endl;
                Insert_Data();
                cout<<endl;
            }
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            Update_Data();
            break;
        }
        case 3:
        {
            system("cls");
            Search_Data();
            break;
        }
        case 4:
        {
            system("cls");
            Delete_Data();
            break;
        }
        case 5:
        {
            system("cls");
            Display_Data();
            break;
        }
        case 6:
        {
            system("cls");
            Display_Backwards();
            break;
        }
        case 7:
        {
            cout<<"Thanks for using our Employee management system.. "<<endl;
            exit(0);
            break;
        }
        default:
        {
            cout<<"Invalid Entry "<<endl;
            break;
        }
        }
    }
    while(choice!= 7);
    return 0;
}
