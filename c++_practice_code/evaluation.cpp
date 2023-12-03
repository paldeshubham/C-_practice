#include<iostream>
using namespace std;
class stack
{
    char data[20];
    int top;
    public:
        stack()
        {
            top=-1;
        }
        char topdata()
        {
            return(data[top]);
        }
        void push(int x)
        {
            data[++top]=x;
        }
        char pop()
        {
            return (data[top--]);
        }
        int full()
        {
            if(top==19)
                return 1;
            return 0;
        }
        int empty()
        {
            if(top==-1)
                return 1;
            return 0;
        }

}
int precedence(int op1, int op2, char op)
{
    
}