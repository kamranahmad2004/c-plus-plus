#include<iostream>
using namespace std;
void Calculating_GPA()
{
    int subject;
    cout<<"Enter number of Subjects:  ";
    cin>>subject;
    float credit[subject], point[subject], sum_total = 0;
    float total, total_credits = 0;
    for(int i=0; i<subject; i++)
    {
        cout<<"Enter Credit of Subject: "<<i+1<<": ";
        cin>>credit[i];
        cout<<"Enter Point of Subject: "<<i+1<<": ";
        cin>>point[i];
    }

    for(int j=0; j<subject; j++)
    {
        total = credit[j]*point[j];
        sum_total += total;
        total_credits += credit[j];
    }

    cout<<"\nYour GPA becomes: "<<sum_total / total_credits<<endl<<endl;
}
// Simple way
void Calculating_CGPA()
{
    int num_sem;
    cout<<"Enter number of Semesters: ";
    cin>>num_sem;
    float gpa, total_sum = 0;
    for(int i=0; i<num_sem; i++)
    {
        cout<<"Enter GPA of Semester: "<<i+1<<": ";
        cin>>gpa;
        total_sum +=gpa;
    }
    cout<<"\nYour CGPA becomes: "<<total_sum/num_sem<<endl<<endl;
}
// Another way
void CGPA_Calculating()
{
    int num_sem;
    cout<<"Enter number of Semesters: ";
    cin>>num_sem;
    float semes[num_sem], sum = 0.0;
    for(int i=0; i<num_sem; i++)
    {
        cout<<"Enter GPA of Semester: "<<i+1<<": ";
        cin>>semes[i];
        sum += semes[i];
    }
    cout<<"\nYour CGPA becomes: "<<sum/num_sem<<endl<<endl;

}

void Calculating_Percentage()
{
    float total_marks;
    float obtained_marks;
    cout<<"Enter total marks: ";
    cin>>total_marks;
    cout<<"Enter obtained marks: ";
    cin>>obtained_marks;

    cout<<"Your percentage becomes: "<<float(obtained_marks / total_marks)* 100;
    cout<<endl<<endl;
}
int main()
{
    cout<<"\n  ---------- ||Calculate Result|| ---------- "<<endl<<endl;
again:
    do
    {
        cout<<"[1] GPA Calculation "<<endl;
        cout<<"[2] CGPA Calculation "<<endl;
        cout<<"[3] Percentage Calculation" <<endl;
        cout<<"[4] Exit "<<endl;
        int choice;
        cout<<"\nEnter your Choice: ";
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            Calculating_GPA();
            break;
        case 2:
            CGPA_Calculating();
            break;
        case 3:
            Calculating_Percentage();
            break;
        case 4:
            cout<<"Thanks for calculating your result here.. "<<endl;
            exit(0);
        default:
            cout<<"Invalid number "<<endl;
            goto again;
        }
    }
    while(true);
    return 0;
}
