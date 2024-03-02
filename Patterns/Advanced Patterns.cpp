#include<iostream>
using namespace std;

void Solid_Rhombus(int n)
{
    for(int i=1; i<=n; i++)
    {
        int spaces = n-i;
        for(int j=1; j<=spaces; j++)
        {
            cout<<" ";
        }

        for(int l=1; l<=n; l++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void Number_Pyramid(int n)
{
    for(int i=1; i<=n; i++)
    {
        int spaces = n-i;
        for(int j=1; j<=spaces; j++)
        {
            cout<<" ";
        }

        for(int l=1; l<=i; l++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void Butterfly_Pattern(int n)
{
    // Upper Half
    for(int i=1; i<=n; i++)
    {
        // 1st Part
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }

        // Spaces
        int spaces = 2*(n-i);
        for(int l=1; l<=spaces; l++)
        {
            cout<<" ";
        }

        // 2nd Part
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    // Lower Half
    for(int i=n; i>=1; i--)
    {
        // 1st Part
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }

        // Spaces
        int spaces = 2*(n-i);
        for(int l=1; l<=spaces; l++)
        {
            cout<<" ";
        }

        // 2nd Part
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void Palindromic_Pattern(int n)
{
    for(int i=1; i<=n; i++)
    {
        int spaces = n-i;
        for(int j=1; j<=spaces; j++)
        {
            cout<<" ";
        }
        // 1st Half Numbers
        for(int j=i; j>1; j--)
        {
            cout<<j<<" ";
        }
        // 2nd Half Numbers
        for(int l=1; l<=i; l++)
        {
            cout<<l<<" ";
        }
        cout<<endl;
    }
}

void Diamond_Pattern(int n)
{
    for(int i=1; i<=n; i++)
    {
        int spaces = n-i;
        for(int j=1; j<=spaces; j++)
        {
            cout<<" ";
        }
        int stars = 2*(i-1);
        for(int l=1; l<stars; l++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    // Lower Half
    for(int i=n; i>=1; i--)
    {
        int spaces = n-i;
        for(int j=1; j<=spaces; j++)
        {
            cout<<" ";
        }
        int stars = 2*(i-1); // --> Odd
        for(int l=1; l<stars; l++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}


int main()
{
    int rows;
    char option, choice;
    cout<<"\n    ------- Advanced Patterns ------- \n"<<endl;
    do
    {
        cout<<"\n a. Solid Rhombus \n b. Number Pyramid \n c. Butterfly Pattern "<<endl;
        cout<<" d. Palindromic Pattern \n e. Diamond Pattern \n"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<"Enter number of rows: ";
        cin>>rows;
        switch(choice)
        {
        case 'a':
        case 'A':
            system("CLS");
            Solid_Rhombus(rows);
            break;

        case 'b':
        case 'B':
            system("CLS");
            Number_Pyramid(rows);
            break;

        case 'c':
        case 'C':
            system("CLS");
            Butterfly_Pattern(rows);
            break;

        case 'd':
        case 'D':
            system("CLS");
            Palindromic_Pattern(rows);
            break;

        case 'e':
        case 'E':
            system("CLS");
            Diamond_Pattern(rows);
            break;

        default:
            cout<<"Invalid character "<<endl;
            break;
        }
        cout<<"\nDo you want to continue (y | n) : ";
        cin>>option;
    }
    while(option == 'y');
    cout<<"\nThanks, Have a nice day!! "<<endl;
    return 0;
}
