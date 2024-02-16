#include <iostream>
using namespace std;
struct Node
{
    int Reg_no;
    string Name;
    float Cgpa;
    Node* next;
};
//Node* Head = NULL;
Node* CS = NULL;
Node* SE = NULL;

// Insert at Last
Node* Insert_Node_at_last(Node* Head)
{
    Node* ptr = new Node;
    cout<<"Enter Registration Number : ";
    cin>>ptr->Reg_no;
    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin,ptr->Name);
    cout<<"Enter CGPA : ";
    cin>>ptr->Cgpa;
    ptr->next = NULL;
    // Checking Head firstly
    if(Head == NULL)
    {
        Head = ptr;
    }
    else
    {
        Node* temp = Head;
        while(temp)  // temp != NULL
        {
            if(temp->next == NULL)
            {
                temp->next = ptr;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    cout<<"Node is Created.. "<<endl;
    return Head;
}

// Insert at Start
Node* Insert_at_Start(Node* Head)
{
    Node* ptr = new Node;
    cout<<"Enter Registration Number : ";
    cin>>ptr->Reg_no;
    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin,ptr->Name);
    cout<<"Enter CGPA : ";
    cin>>ptr->Cgpa;
    ptr->next = NULL;
    // Checking Head firstly
    if(Head == NULL)
    {
        Head = ptr;
    }
    else
    {
        ptr->next = Head;
        Head = ptr;
    }
    cout<<"Node is inserted successfully.. "<<endl;
    return Head;
}

// Insert Before Specific Node
Node* Insert_before_Specific_Node(Node* Head)
{
    Node* ptr = new Node;
    int reg;
    cout<<"Enter Registration Number for Insert Before Specific Node : ";
    cin>>reg;
    cout<<"Enter Registration Number : ";
    cin>>ptr->Reg_no;
    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin,ptr->Name);
    cout<<"Enter CGPA : ";
    cin>>ptr->Cgpa;
    ptr->next = NULL;
    // Checking Head Firstly
    if(Head == NULL)
    {
        Head = ptr;
    }
    else if(Head->Reg_no == reg)
    {
        ptr->next = Head;
        Head = ptr;
    }
    else
    {
        Node* temp = Head;
        while(temp)  // temp != NULL
        {
            if(temp->next->Reg_no == reg)
            {
                ptr->next = temp->next;
                temp->next = ptr;
                break;
            }
            else if(temp->next->next == NULL )
            {
                cout<<"Data does not exist "<<endl;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    cout<<"Node is inserted successfully.. "<<endl;
    return Head;
}

// Insert After Specific Node
Node* Insert_After_Specific_Node(Node* Head)
{
    Node* ptr = new Node;
    int reg;
    cout<<"Enter Specific Registration Number : ";
    cin>>reg;
    cout<<"Enter Registration Number : ";
    cin>>ptr->Reg_no;
    cout<<"Enter Name : ";
    cin.ignore();
    getline(cin,ptr->Name);
    cout<<"Enter CGPA : ";
    cin>>ptr->Cgpa;
    ptr->next = NULL;
    if(Head == NULL)
    {
        Head = ptr;
    }
    else
    {
        Node* temp = Head;
        while(temp)  // temp != NULL
        {
            if(temp->Reg_no == reg)
            {
                ptr->next = temp->next;
                temp->next = ptr;
                break;
            }
            else if(temp->next == NULL)
            {
                cout<<"This Node is Last.. your Data does not found "<<endl;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    cout<<"Node is inserted successfully.. "<<endl;
    return Head;
}

// Search Node
Node* Search_Node(Node* Head)
{
    if(Head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        int reg;
        cout<<"Enter Registration Number for Search Node : ";
        cin>>reg;
        Node* temp = Head;
        while(temp)  // temp != NULL
        {
            if(temp->Reg_no == reg)
            {
                cout<<"Searching Data is Found "<<endl;
                cout<<"\nRegistration Number is : "<<temp->Reg_no<<endl;
                cout<<"Name is : "<<temp->Name<<endl;
                cout<<"CGPA is : "<<temp->Cgpa<<endl;
                break;
            }
            else if(temp->next == NULL)
            {
                cout<<"Data does not is Exist "<<endl;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    return Head;
}

// Update Node
Node* Update_Node(Node* Head)
{
    if(Head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        int reg;
        cout<<"Enter specific Registration Number : ";
        cin>>reg;
        Node* temp = Head;
        while(temp)  // temp != NULL
        {
            if(temp->Reg_no == reg)
            {
                cout<<"Data is Found \n"<<endl;
                cout<<"Enter Updated Registration Number : ";
                cin>>temp->Reg_no;
                cout<<"Enter Updated Name : ";
                cin.ignore();
                getline(cin,temp->Name);
                cout<<"Enter Updated CGPA : ";
                cin>>temp->Cgpa;
                break;
            }
            else if(temp->next == NULL)
            {
                cout<<"Data does not Exist "<<endl;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    cout<<"Data is Updated Successfully.. "<<endl<<endl;
    return Head;
}

// Delete First Node
Node* Delete_First_Node(Node* Head)
{
    if(Head == NULL)
    {
        cout<<"List is Empty ";
    }
    else
    {
        Head = Head->next;
    }
    cout<<"Deleted First Node Successfully.. "<<endl<<endl;
    return Head;
}
// Delete Last Node
Node* Delete_Last_Node(Node* Head)
{
    if(Head == NULL)
    {
        cout<<"List is Empty ";
    }
    else if(Head->next == NULL)  // Condition just for 1 Node
    {
        Head = NULL; // Deleting Head (1st Node)
    }
    else
    {
        Node* temp = Head;
        while(temp)
        {
            if(temp->next->next == NULL)
            {
                temp->next = temp->next->next;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    cout<<"Deleted Last Node Successfully.. "<<endl<<endl;
    return Head;
}
// Delete Specific Node
Node* Delete_Specific_Node(Node* Head)
{
    int reg;
    cout<<"Enter Registration Number for Deleting Specific Node : ";
    cin>>reg;
    if(Head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    // Checking Head
    else if(Head->Reg_no == reg)
    {
        Head = Head->next;
    }
    else
    {
        Node* temp = Head;
        while(temp)  // temp != NULL
        {
            if(temp->next->Reg_no == reg)
            {
                temp->next = temp->next->next;
                break;
            }
            else if(temp->next->next== NULL)
            {
                cout<<"Data does not Exist "<<endl;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    cout<<"Deleted Node Successfully.. "<<endl<<endl;
    return Head;
}
// Display Node
Node* Display_Node(Node* Head)
{
    if(Head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        Node* temp = Head;
        cout<<"\n*** Displaying Information *** \n"<<endl;
        while(temp != NULL)  // temp != NULL
        {
            cout<<"Registration Number is : "<<temp->Reg_no<<endl;
            cout<<"Name is : "<<temp->Name<<endl;
            cout<<"CGPA is : "<<temp->Cgpa<<endl;
            temp = temp->next;
            cout<<endl;
        }
    }
    return Head;
}

void MAIN()
{
    int ch, choice;
    cout<<"\n          ---------------  WELCOME TO STUDENT'S MANAGEMENT SYSTEM  ---------------- "<<endl<<endl;
    cout<<"\n         1.  CS Department                   ||             2.  SE Department "<<endl;
    cout<<"\nEnter which Department's List do you want to create (Select by it's number) : ";
    cin>>ch;
    if(ch == 1)
    {
        do
        {
            cout<<"\n-------- List of CS ---------"<<endl<<endl;
            cout<<"[1]. Insert Node at Last "<<endl;
            cout<<"[2]. Insert Node at Start "<<endl;
            cout<<"[3]. Insert Before Specific Node "<<endl;
            cout<<"[4]. Insert After Specific Node "<<endl;
            cout<<"[5]. Search Node Data "<<endl;
            cout<<"[6]. Update Node Data "<<endl;
            cout<<"[7]. Delete Node "<<endl;
            cout<<"[8]. Display Data "<<endl;
            cout<<"[9]. Exit "<<endl;
            cout<<"\nEnter your choice from (1 - 9): ";
            cin>>choice;
            switch(choice)
            {
            case 1:
            {
                system("cls");
                int num;
                cout<<"\nEnter how many nodes do you want to insert : ";
                cin>>num;
                for(int i=0; i<num; i++)
                {
                    CS = Insert_Node_at_last(CS);
                    cout<<endl;
                }
                break;
            }
            case 2:
            {
                system("cls");
                CS = Insert_at_Start(CS);
                break;
            }
            case 3:
            {
                system("cls");
                CS = Insert_before_Specific_Node(CS);
                break;
            }
            case 4:
            {
                system("cls");
                CS = Insert_After_Specific_Node(CS);
                break;
            }
            case 5:
            {
                system("cls");
                CS = Search_Node(CS);
                break;
            }
            case 6:
            {
                system("cls");
                CS = Update_Node(CS);
                break;
            }
            case 7:
            {
                system("cls");
                char sel;
                cout<<"a. Delete First Node Data "<<endl;
                cout<<"b. Delete Last Node Data "<<endl;
                cout<<"c. Delete Specific Node Data "<<endl;
                cout<<"\nSelect one of them from (a - c) : ";
                cin>>sel;
                switch(sel)
                {
                case 'a':
                {
                    CS = Delete_First_Node(CS);
                    break;
                }
                case 'b':
                {
                    CS = Delete_Last_Node(CS);
                    break;
                }
                case 'c':
                {
                    CS = Delete_Specific_Node(CS);
                    break;
                }
                default:
                {
                    cout<<"Invalid Entry "<<endl;
                    break;
                }
                }
                break;
            }
            case 8:
            {
                system("cls");
                CS = Display_Node(CS);
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                cout<<"Invalid Entry "<<endl;
                break;
            }
            }
        }
        while(ch != 9);
    }
    else if(ch == 2)
    {
        do
        {
            cout<<"\n-------- List of SE ---------"<<endl;
            cout<<"\n[1]. Insert Node at Last "<<endl;
            cout<<"[2]. Insert Node at Start "<<endl;
            cout<<"[3]. Insert Before Specific Node "<<endl;
            cout<<"[4]. Insert After Specific Node "<<endl;
            cout<<"[5]. Search Node Data "<<endl;
            cout<<"[6]. Update Node Data "<<endl;
            cout<<"[7]. Delete Node "<<endl;
            cout<<"[8]. Display Data "<<endl;
            cout<<"[9]. Exit "<<endl;
            int option;
            cout<<"\nEnter your choice from (1 - 9): ";
            cin>>option;
            switch(option)
            {
            case 1:
            {
                system("cls");
                int num;
                cout<<"\nEnter how many nodes do you want to insert : ";
                cin>>num;
                for(int i=0; i<num; i++)
                {
                    SE = Insert_Node_at_last(SE);
                    cout<<endl;
                }
                break;
            }
            case 2:
            {
                system("cls");
                SE = Insert_at_Start(SE);
                break;
            }
            case 3:
            {
                system("cls");
                SE = Insert_before_Specific_Node(SE);
                break;
            }
            case 4:
            {
                system("cls");
                SE = Insert_After_Specific_Node(SE);
                break;
            }
            case 5:
            {
                system("cls");
                SE = Search_Node(SE);
                break;
            }
            case 6:
            {
                system("cls");
                SE = Update_Node(SE);
                break;
            }
            case 7:
            {
                system("cls");
                char select;
                cout<<"a. Delete First Node Data "<<endl;
                cout<<"b. Delete Last Node Data "<<endl;
                cout<<"c. Delete Specific Node Data "<<endl;
                cout<<"\nSelect one of them from (a - c) : ";
                cin>>select;
                switch(select)
                {
                case 'a':
                {
                    SE = Delete_First_Node(SE);
                    break;
                }
                case 'b':
                {
                    SE = Delete_Last_Node(SE);
                    break;
                }
                case 'c':
                {
                    SE = Delete_Specific_Node(SE);
                    break;
                }
                default:
                {
                    cout<<"Invalid Entry "<<endl;
                    break;
                }
                }
                break;
            }
            case 8:
            {
                system("cls");
                SE = Display_Node(SE);
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                cout<<"Invalid Entry "<<endl;
                break;
            }
            }
        }
        while(ch != 9);
    }
    else
    {
        exit(0);
    }
}
int main()
{
    //system("Color E4");
    MAIN();
    return 0;
}

