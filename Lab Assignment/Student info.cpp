#include<iostream>
using namespace std;
struct Student
{
    int reg_no;
    string name, branch;
    float Cgpa;
};
Student stu[50];

void insertData(string Name, int reg, string Branch, float cgpa, int index)
{
    stu[index].reg_no = reg;
    stu[index].name = Name;
    stu[index].branch = Branch;
    stu[index].Cgpa = cgpa;
}

void Linear_Search()
{
    int num, reg;
    cout<<"Enter Specific Reg no to Search : ";
    cin>>reg;
    for(int i=0; i<50; i++)
    {
        if(stu[i].reg_no == reg)
        {
            cout<<"Student's Reg no is : "<<stu[i].reg_no<<endl;
            cout<<"Student's Name is : "<<stu[i].name<<endl;
            cout<<"Student's Branch is : "<<stu[i].branch<<endl;
            cout<<"Student's CGPA is : "<<stu[i].Cgpa<<endl;
        }
    }
}

void Bubble_Sort()
{
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50-1; j++)
        {
            if(stu[j].reg_no > stu[j+1].reg_no)
            {
                int temp_reg = stu[j].reg_no;
                stu[j].reg_no = stu[j+1].reg_no;
                stu[j+1].reg_no = temp_reg;

                string temp_name = stu[j].name;
                stu[j].name = stu[j+1].name;
                stu[j+1].name = temp_name;

                string temp_branch = stu[j].branch;
                stu[j].branch = stu[j+1].branch;
                stu[j+1].branch= temp_branch;

                float temp_CGPA = stu[j].Cgpa;
                stu[j].Cgpa = stu[j+1].Cgpa;
                stu[j+1].Cgpa = temp_CGPA ;
            }
        }
    }
    for(int i=0; i<50; i++)
    {
        cout<<i + 1<<" : "<<"Student's Registration no is : "<<stu[i].reg_no<<endl;
        cout<<i + 1<<" : "<<"Student's Name is : "<<stu[i].name<<endl;
        cout<<i + 1<<" : "<<"Student's Branch is : "<<stu[i].branch<<endl;
        cout<<i + 1<<" : "<<"Student's CGPA is : "<<stu[i].Cgpa<<endl;
    }
}

void Binary_Search()
{
    int low = 0, high = 50-1, search_val, mid;
    cout<<"\nEnter value to Search : ";
    cin>>search_val;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(search_val == stu[mid].reg_no)
        {
            cout<<"Student's Reg no is : "<<stu[mid].reg_no<<endl;
            cout<<"Student's Name is : "<<stu[mid].name<<endl;
            cout<<"Student's Branch is : "<<stu[mid].branch<<endl;
            cout<<"Student's CGPA is : "<<stu[mid].Cgpa<<endl;
            break;
        }
        else if(search_val < stu[mid].reg_no)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
}

void Insertion_Sort()
{
    for(int i=1; i<50; i++)
    {
        float cgpa = stu[i].Cgpa;
        string name = stu[i].name;
        string branch = stu[i].branch;
        int regNo = stu[i].reg_no;
        int j = i-1;
        while(j>=0 && cgpa > stu[j].Cgpa)
        {
            stu[j+1] = stu[j];
            j--;
        }
        stu[j+1].Cgpa = cgpa;
        stu[j+1].name = name;
        stu[j+1].branch = branch;
        stu[j+1].reg_no = regNo;
    }
}


void Display_Data()
{
    int num;
    cout<<"\n\nDisplaying Student's Data "<<endl;
    for(int i=0; i<50; i++)
    {
        cout<<i + 1<<" : "<<"Student's Registration no is : "<<stu[i].reg_no<<endl;
        cout<<i + 1<<" : "<<"Student's Name is : "<<stu[i].name<<endl;
        cout<<i + 1<<" : "<<"Student's Branch is : "<<stu[i].branch<<endl;
        cout<<i + 1<<" : "<<"Student's CGPA is : "<<stu[i].Cgpa<<endl;
    }
}
int main()
{
    int choice;
    insertData("Umar",1,"bscs",4,0);
    insertData("kamran",10,"bscs",3.9,1);
    insertData("Ali",20,"bscs",3.8,2);
    insertData("Ahmad",30,"bscs",3.7,3);
    insertData("Abrahim",40,"bscs",3.6,4);
    insertData("Hassan",50,"bscs",3.5,5);
    insertData("Muhannad",11,"bscs",3.4,6);
    insertData("Bilal",12,"bscs",3.3,7);
    insertData("Hussain",13,"bscs",3.2,8);
    insertData("Afzal",14,"bscs",3.1,9);
    insertData("Faisal",16,"bscs",2,10);
    insertData("Fakhir",22,"bscs",2.9,11);
    insertData("Mubashar",72,"bscs",2.8,12);
    insertData("Sohaib",63,"bscs",2.7,13);
    insertData("Shahzaz",64,"bscs",2.6,14);
    insertData("farooq",7,"bscs",2.5,15);
    insertData("Abdullah",8,"bscs",2.4,16);
    insertData("Asim",37,"bscs",2.3,17);
    insertData("Bashir",33,"bscs",2.2,18);
    insertData("Luqman",35,"bscs",2.1,19);
    insertData("Humair",18,"bscs",1,20);
    insertData("Umair",97,"bscs",3.2,21);
    insertData("Hassam",66,"bscs",3.3,22);
    insertData("Zain",9,"bscs",3.5,23);
    insertData("Tabish",190,"bscs",3.6,24);
    insertData("Iqbal",167,"bscs",3.7,25);
    insertData("Saad",108,"bscs",3.8,26);
    insertData("Ateeb",109,"bscs",3.9,27);
    insertData("Adeel",99,"bscs",4,28);
    insertData("Waseem",89,"bscs",4,29);
    insertData("Subhan",56,"bscs",4,30);
    insertData("Ayan",31,"bscs",4,31);
    insertData("Abdul rehman",41,"bscs",4,32);
    insertData("Ramish",49,"bscs",4,33);
    insertData("Najam",48,"bscs",3.2,34);
    insertData("Faizan",47,"bscs",3.1,35);
    insertData("Shakeel",46,"bscs",3.1,36);
    insertData("Asad",67,"bscs",3.1,37);
    insertData("Zaid",78,"bscs",3.4,38);
    insertData("Nabeel",91,"bscs",3.7,39);
    insertData("Shahzaib",138,"bscs",3.8,40);
    insertData("Nawaz",267,"bscs",3.9,41);
    insertData("Muhammad",154,"bscs",3.1,42);
    insertData("Zaryab",45,"bscs",4,43);
    insertData("Asif",143,"bscs",2,44);
    insertData("Atif",132,"bscs",2.5,45);
    insertData("Ahtesham",100,"bscs",2.6,46);
    insertData("Masood",44,"bscs",2.7,47);
    insertData("Imran",43,"bscs",2.8,48);
    insertData("Rashid",42,"bscs",4,49);
    cout<<"[1] Linear Search \n[2] Bubble Sort \n[3] Binary Search \n[4] Insertion Sort\n[5] Display Data "<<endl;
    do
    {
    cout<<"\nEnter your Choice : ";
    cin>>choice;

        switch(choice)
        {
        case 1:
        {
            Linear_Search();
            break;
        }
        case 2:
        {
            Bubble_Sort();
            break;
        }
        case 3:
        {
            Binary_Search();
            break;
        }
        case 4:
        {
            Insertion_Sort();
            Display_Data();
            break;
        }
        case 5:
        {
            Display_Data();
            break;
        }
        default:
        {
            cout<<"Invalid Entry "<<endl;
            exit(0);
        }
        }
    }
        while(choice != 6);
        return 0;
}
