#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long int MAX=100000;

struct STACK{
    int top;
    char elements[MAX];
};

void MakeNull(STACK &S)
{
    S.top=-1;
}

bool Empty(STACK S)
{   if ( S.top < 0 )
        return true;
    else
        return false;
}

int Top( STACK S )
{   if ( Empty( S ) )
        return false;
    else
        return ( S.elements[ S.top ] );
}

void Pop( STACK &S )
{
    if ( Empty (S ) )
        cout<< "栈空";
    else
        S.top = S.top-1;
}
int cal(int b1,int b2, char c)
{
    if(c=='+')
        return b1+b2;
    if(c=='-')
        return b1-b2;
    if(c=='*')
        return b1*b2;
    if(c=='/')
        return b1/b2;
}

void Push ( int x, STACK &S )
{
    if ( S.top == MAX-1)
        cout<< "栈满";
    else
    {  S.top = S.top + 1 ;
        S.elements[ S.top ] = x ;
    }
}

bool judge(char a, char b)
{
 if(a=='+'||a=='-')
  if(b=='*'||b=='/')
   return false;
 return true;
}

int main()
{
    bool flag;
    STACK num;
    STACK op;
    char ar_num[MAX];
    char c;
    int b[2];
    cin>>ar_num;
    for(int i=0;ar_num[i]!='\0';i++)
    {
        flag=true;
        c='\0';
        if(ar_num[i]>='0'&&ar_num[i]<='9')
        Push(ar_num[i]-'0',num);
        else
        {
            if(Empty(op))
            {
                Push(ar_num[i],op);
                 flag=false;
            }
            if(judge(ar_num[i],Top(op))&&flag)
            {
                Push(ar_num[i],op);
            }
            if(flag&&!judge(ar_num[i],Top(op)))//如果进栈的运算符级别低于栈顶，则出栈
            {
                c=Top(op);
                Pop(op);
                b[1]=Top(num);
                Pop(num);
                b[0]=Top(num);
                Pop(num);
                i--;
            }
             if(c!='\0')
            {
                Push(cal(b[0],b[1],c),num);//计算
            }
        }
    }
    while(!Empty(op))
    {
        c=Top(op);
        Pop(op);
        b[1]=Top(num);
        Pop(num);
        b[0]=Top(num);
        Pop(num);
        Push(cal(b[0],b[1],c),num);
    }
    if(num.top=1)
    cout<<Top(num)<<endl;
    return 0;
}
