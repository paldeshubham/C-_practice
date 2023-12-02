#include<iostream>
using namespace std;

struct node{
    char data;
    node*left;
    node *right;

};
class stack
{
    node *data[10];
    int top;
    public:
    stack()
    {
        top=-1;

    }
    node *topdata()
    {
        return(data[top]);
    }
    void insert(node *p)
    {
        data[++top]=p;
    }
    node *pop()
    {
        return(data[top--]);
    }   
};

node *create(char postfix[10])
{
    node *p;
} 