//可以转换成，每个人都拿到失败的那份经验，然后一部分人拿到成功-失败的经验差
//这样就变成了0-1背包问题。

#include <bits/stdc++.h>
using namespace std;

struct num{
    int lose,win,delta,use;
}nums[1005];
int n,x;
int f[1005];

int max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> nums[i].lose >> nums[i].win >> nums[i].use;
        nums[i].delta = nums[i].win - nums[i].lose;
    }
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= nums[i].use; j--){
            f[j] = max(f[j],f[j-nums[i].use]+nums[i].delta);
        }
    }
    long long s = f[x];
    for(int i = 1; i <= n; i++){
        s += nums[i].lose;
    }
    cout << (5 * s);

    return 0;
}