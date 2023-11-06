#include<iostream>
using namespace std;
struct Student{
    int roll_no;
    char name[80];
    float SGPA;
};
void accept(struct Student list[5]);
void display(struct Student list[80]);
void bubblesort(struct Student list[5]);
void search(struct Student list[5]);

int main()
{
    struct Student data[20];
    accept(data);
    cout << "\n bubble sort";
    bubblesort(data);
    display(data);
}
void accept(struct Student list[5])
{
    int i;
    for (i=0;i<5;i++)
    {
        cout <<"Enter Roll no,name ,SGPA";
        cin >> list[i].roll_no >>list[i].name >> list[i].SGPA;

    }
}
void display(struct Student list[80])
{
    int i;
    for(i=0;i<5;i++){

        cout <<"\n"<< list[i].roll_no <<"\t"<< list[i].name <<"\t"<< list[i].SGPA;
    }
}
void bubblesort(struct Student list[5]  )
{
    int i,j;
    struct Student temp;
    for(int i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(list[i].roll_no > list[j+1].roll_no)
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;

            }
        }
    }
}
void search(struct Student list[5])
{
    float SGPA;
    int i;
    cout <<"enter SGPA";
    cin >> SGPA;
    cout <<"\n roll no \t name \t SGPA";
    for(i=0;i<5;i++)
    {
        if(SGPA==list[i].roll_no)
        {
            cout << list[i].roll_no << "\t" << list[i].name <<"\t" << list[i].SGPA;
        }
    }
}