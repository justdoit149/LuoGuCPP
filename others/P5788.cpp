//单调栈模版题
#include <bits/stdc++.h>
using namespace std;

int a[3000005],b[3000005];

stack<int> sta;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    //本题数据规模较大，scanf、printf比cin、cout快一些
    for(int i = n; i >= 1; i--){
        //关注数据后面的数据，所以从后往前入栈，前面的数据在栈里找后面的数据。
        while(!sta.empty() && a[sta.top()] <= a[i]){
            sta.pop();
        }
        if(sta.empty()){
            b[i] = 0;
        }else{
            b[i] = sta.top();
        }
        sta.push(i);
    }
    for(int i = 1; i <= n; i++) printf("%d ",b[i]);


    return 0;
}