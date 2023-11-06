#include<iostream>
using namespace std;
int main()
{
    int a[10]={2,6,5,4,8,9,12,45,35,68};
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=1;j<10;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    cout <<"sorted array is:\n";
    for(i=0;i<10;i++)
    {
        cout << a[i] <<"\t";
    }
}