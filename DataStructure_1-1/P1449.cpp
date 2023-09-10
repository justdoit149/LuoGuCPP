//使用栈来完成

#include <bits/stdc++.h>
using namespace std;
stack<int> n;
char ch;
int s,x,y;
int main()
{
    while(ch!='@')
    {
        ch=getchar();
        if(ch == '+'){//边输入边计算，用过的就弹出，算的结果压入
            x=n.top();
            n.pop();
            y=n.top();
            n.pop();
            n.push(x+y);
        }else if(ch == '-'){
            x=n.top();
            n.pop();
            y=n.top();
            n.pop();
            n.push(y-x);
        }else if(ch == '*'){
            x=n.top();
            n.pop();
            y=n.top();
            n.pop();
            n.push(x*y);
        }else if(ch == '/'){
            x=n.top();
            n.pop();
            y=n.top();
            n.pop();
            n.push(y/x);
        }else if(ch == '.'){
            n.push(s);
            s=0;//分隔记得清空s
        }else{
            s=s*10+ch-'0';//s储存数字，一位一位读取
        }
    }
    printf("%d\n",n.top());
    return 0;
}