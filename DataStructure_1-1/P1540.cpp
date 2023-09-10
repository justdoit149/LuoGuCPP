#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n,temp,ans=0;
    queue<int> a;//先进先出，故想到用队列模拟
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        bool findnum = 0;
        int a_size = a.size();
        for(int j = 0; j < a_size; j++){
            //查找在不在队列中，可以先弹出再压入，但这样必须严格遍历一遍，数据大时不推荐
            int temp1 = a.front();
            if(temp == temp1) findnum = 1;
            a.pop();
            a.push(temp1);
        }
        if(findnum == 0){
            if(a_size == m) a.pop();
            a.push(temp);
            ans++;
        }
    }
    cout << ans;
    return 0;
}