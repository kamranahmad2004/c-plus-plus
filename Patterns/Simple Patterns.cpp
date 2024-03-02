#include<iostream>
using namespace std;
void Solid_Rectangle(int n)
{
    int m = 6;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void Hollow_Rectangle(int n)
{
    int m = 6;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i==1 || i==n || j==1 || j==m)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void Half_Pyramid(int n)  // the inner loop will run until the value of j has reached the value of i (inner loop).
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void Inverted_Half_Pyramid(int n)
{
    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void Inverted_Half_Pyramid_Rotate(int n)  // rotate by 180 deg
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=(n-i); j++)
        {
            cout<<" ";
        }
        for(int k=1; k<=i; k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void Half_Pyramid_Numbers(int rows)
{
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void Inverted_Half_Pyramid_Numbers(int rows)
{
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=rows-i+1; j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void Floyds_Triangle(int rows)
{
    int num = 1;
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

void ZeroOne_Triangle(int rows)
{
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=i; j++)
        {
            int sum = i+j;
            if(sum % 2 == 0)  // if sum is even then print 1, otherwise print 0.
            {
                cout<<"1 ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    int rows;
    int choice;
    char ch;
    cout<<" ----- PATTERNS ---- \n"<<endl;
    do
    {
        cout<<"\n[1]. Solid Rectangle \n[2]. Hollow Rectangle \n[3]. Half Pyramid \n[4]. Inverted Half Pyramid \n[5]. Inverted Half Pyramid Rotate\n";
        cout<<"[6]. Half Pyramid of Numbers \n[7]. Inverted Half Pyramid of Numbers \n[8]. Floyd's Triangle \n[9]. 0-1 Triangle\n"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"Enter no of rows: ";
        cin>>rows;
        switch(choice)
        {
        case 1:
            system("CLS");
            Solid_Rectangle(rows);
            break;
        case 2:
            system("CLS");
            Hollow_Rectangle(rows);
            break;
        case 3:
            system("CLS");
            Half_Pyramid(rows);
            break;
        case 4:
            system("CLS");
            Inverted_Half_Pyramid(rows);
            break;
        case 5:
            system("CLS");
            Inverted_Half_Pyramid_Rotate(rows);
            break;
        case 6:
            system("CLS");
            Half_Pyramid_Numbers(rows);
            break;
        case 7:
            system("CLS");
            Inverted_Half_Pyramid_Numbers(rows);
            break;
        case 8:
            system("CLS");
            Floyds_Triangle(rows);
            break;
        case 9:
            system("CLS");
            ZeroOne_Triangle(rows);
            break;
        default:
            cout<<"Invalid Entry "<<endl;
        }
        cout<<"Do you want to continue (y | n) : ";
        cin>>ch;
    }
    while(ch != 'n');
    cout<<"\nThanks for using these Patterns "<<endl;
    return 0;
}
