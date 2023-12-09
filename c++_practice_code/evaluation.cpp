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

};
int evaluate(int op1, int op2, char op)
{
    if(op=='+')
    return op1+op2;

    if(op=='-')
    return op1-op2;

    if(op=='*')
        return op1*op2;
    
    if(op=='/')
    return op1/op2;

    if(op=='%')
    return op1%op2;
}

void postfix_evaluation(char postfix[20])
{
    stack s;
    int i=0,j=0;
    int op1,op2,result;
    int x;
    for(i=0;postfix[i]!='\0';i++)
    {
        char token=postfix[i];
        if(isalnum(token))
        {
            cout << "Enter the value of "<<token<<":";
            cin>>x;
            s.push(char(x));
        }
        else{
            op1=s.pop();
            op2=s.pop();
            result=evaluate(op1,op2,token);
            s.push(char(result));
        }
    }
    result=s.pop();
    cout<<"result is:"<<result;
}
void prefix_evaluate(char prefix[20])
{
    int i=0,j=0;
    char token;
    stack s;
    int op1,op2,result,x;
    for(i=0;prefix[i]!='\0';i++)
    {
        
    }
    i--;
    
    for(j=0;i>=0;j++,i--)
    {
        token=prefix[i];
        if(isalnum(token))
        {
            cout << "Enter the value of "<<token<<":";
            cin>>x;
            s.push(char(x));
        }
        else{
            op1=s.pop();
            op2=s.pop();
            result=evaluate(op1,op2,token);
            s.push(char(result));
        }
    }
    result=s.pop();
    cout<<"result is:"<<result;
    
}
int main()
{
    char postfix[20],prefix[20];
    cout<<"enter postfix expression:";
    cin>>postfix;
    postfix_evaluation(postfix);
    cout<<"\n";
    
    
    cout<<"enter prefix expression:";
    cin>>prefix;
    prefix_evaluate(prefix);
    
}