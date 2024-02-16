#include <iostream>
#include<fstream>
using namespace std;
class Manage_TODO
{
public:
    string ToDo[20];
    int index = 0, array_size = 0;
    virtual void task () = 0;
    Manage_TODO()
    {
        int i = 0;
        ifstream read;
        read.open("Data.txt");
        if(read)
        {
            while(read.eof() == 0)
            {
                getline(read,ToDo[i]);
                i++;
            }
        }
        else
        {
            ofstream write("Data.txt");
        }
        read.close();
    }
    void WriteData()
    {
        int i = 0;
        ofstream write("Data.txt");
        while(ToDo[i] != "")
        {
            write<<ToDo[i]<<endl;
            i++;
        }
        write.close();
    }

    void check_size()
    {
        int i=0;
        while(ToDo[i] != "")
        {
            array_size++;
            i++;
        }
    }
    void show_ToDo()
    {
        int i = 0;
        while(ToDo[i] != "")
        {
            cout<<i+1<<". "<<ToDo[i]<<endl;
            i++;
        }
    }
};
class Add_Task : public Manage_TODO
{
public:
    char opt;
    void task()
    {
        check_size();
        int i = array_size;
        do
        {
            cout<<"\nEnter your TODO Task : ";
            cin.ignore();
            getline(cin,ToDo[i]);
            i++;
            cout<<"Do you want to Add more TODO Task ? (Y/N) : ";
            cin>>opt;
        }
        while(opt == 'y');
        cout<<"Your task has been added successfully \n";
        WriteData();
    }
};
class Update_Task : public Manage_TODO
{
public:
    void task()
    {
        if(ToDo[0] == "")
        {
            cout<<"TODO List is Empty, there is no task to update "<<endl;
        }
        else
        {
            show_ToDo();
            cout<<"\n\nSelect Task no from this List for Update : ";
            cin>>index;
            index--;
            cout<<"Enter your Updated Task : ";
            cin.ignore();
            getline(cin,ToDo[index]);
            cout<<"\nYour Task has been Updated Successfully  "<<endl;
            WriteData();
        }
    }
};
class Search_Task : public Manage_TODO
{
public:
    void task()
    {
        if(ToDo[0] == "")
        {
            cout<<"TODO List is Empty, there is no task to Search "<<endl;
        }
        else
        {

            cout<<"Enter the Number of Task which you want to search : ";
            cin>>index;
            index--;
            cout<<"Your Searching Task is : "<<ToDo[index]<<endl;
            WriteData();
        }
    }
};
class Delete_Task : public Manage_TODO
{
public:
    void task()
    {
        if(ToDo[0] == "")
        {
            cout<<"TODO List is Empty, there is no task for Delete "<<endl;
        }
        else
        {
            check_size();
            cout<<"What you want to Delete from your TODO List (Given below) \n"<<endl;
            show_ToDo();
            cout<<"\nEnter the number of task :";
            cin>>index;
            index--;
            while(index < array_size) //index = 0
            {
                ToDo[index] = ToDo[index+1];
                index++;
            }
            cout<<"Your task has been deleted successfully ";
            WriteData();
        }
    }
};
class List_Task : public Manage_TODO
{
public:
    void task()
    {
        if(ToDo[0] == "")
        {
            cout<<"You don't have any TODO Task yet "<<endl;
        }
        else
        {

            cout<<"List of your TODO Task is "<<endl<<endl;
            show_ToDo();
            WriteData();
        }
    }
};
void menu()
{
    char yn;
    int choice;
    Manage_TODO* manage;
    cout<<" ---------------------------- " <<endl;
    cout<<"  Welcome to your ToDo List "<<endl;
    cout<<" ---------------------------- " <<endl;
    do
    {
        cout<<" \n[1]. Add new Task \n[2]. Update a Task \n[3]. Search for a Task " <<endl;
        cout<<"[4]. Delete a Task \n[5]. View all Tasks\n" <<endl;
        cout<<"Enter your Choice : ";
        cin>>choice;
        if(choice < 1 || choice > 5)
        {
            while(choice <1 || choice > 5)
            {
                cout<<"\nYou Entered Invalid Number : " <<endl;
                cout<<"Enter a valid choice : ";
                cin>>choice;
            }
        }
        if(choice == 1)
        {
            Add_Task task;
            manage = &task;
            manage->task();
        }
        else if(choice == 2)
        {

            Update_Task upd;
            manage = &upd;
            manage->task();
        }
        else if(choice == 3)
        {
            Search_Task Search;
            manage = &Search;
            manage->task();
        }
        else if(choice == 4)
        {
            Delete_Task Delete;
            manage = &Delete;
            manage->task();
        }
        else if(choice ==  5)
        {
            List_Task  List;
            manage = &List;
            manage->task();
        }
        else
        {
            break;
        }
        cout<<"\nEnter y if you want to Continue list, otherwise Enter n to stop (From List) : ";
        cin>>yn;
        system("CLS");
    }
    while(yn == 'y');
}
int main()
{
    system("color E4");
    menu();
    return 0;
}
