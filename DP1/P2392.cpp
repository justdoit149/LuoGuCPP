//思想：总时间是4个时间的和，4个时间都相对是一个独立的单位，故抽象出一个solve()函数来解决
//对于每一科，转化为：将所给的数据分成两份，使得它们的和尽可能接近，然后其中和较大的就是用时。
//因此转换成每个数据选或者不选的0-1背包，需要看最后大于等于中值的最小数是多少
//bool f[j][k]表示前j个是否有和为k的取法。
//f[j][k] = (f[j-1][k] || f[j-1][k-ss[i][j]]);
#include <bits/stdc++.h>
using namespace std;

int ss[5][25];//有4行，从1开始用，所以要开5哎
int s[5];

int solve(int i){
    int sum = 0;
    bool f[1205] = {1};//求和能得到哪些数。注意f[0] = 1
    for(int j = 1; j <= s[i]; j++){
        sum += ss[i][j];
    }
    for(int j = 1; j <= s[i]; j++){
        for(int k = sum; k >= ss[i][j]; k--){
            f[k] = (f[k] || f[k-ss[i][j]]);
        }
    }
    for(int j = (sum + 1) / 2; ; j++){
        if(f[j] == true){
            return j;
        }
    }
}

int main(int argc, char const *argv[])
{
    int ans = 0;
    for(int i = 1; i <= 4; i++){
        cin >> s[i];
    }
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= s[i]; j++){
            cin >> ss[i][j];
        }
    }
    for(int i = 1; i <= 4; i++){
        ans += solve(i);
    }
    cout << ans;
    return 0;
}
