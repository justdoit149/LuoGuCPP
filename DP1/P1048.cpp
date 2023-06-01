//经典背包DP。

#include <bits/stdc++.h>
using namespace std;

int t[105],v[105];//t记录时间（代价），v记录价值（收益）
int f[1005];//f[i]表示当总时间为i时的最大价值。
//这个数组滚动使用，也就是多次被更新覆盖。
//这个数组一开始初始就默认是0，不用特意初始化。

int max(int a,int b){
    return a > b ? a : b;
}

int main(){
    int T,M;
    cin >> T >> M;
    for(int i = 1;i <= M; i++){
        cin >> t[i] >> v[i];
    }

    //以下部分是核心代码
    //只考虑在前i个里选，找符合要求的情况
    //当i变为i+1时，可能不选第i+1个，那这时候总价值和前i个相同，是f[i]
    //如果选第i+1个，则转化为在前i个里找，但是这时候价值上限需要减掉第i+1个的价值
    //也就是此时的价值是f[j-t[i]]+v[i]。我们需要在这两个里选大的。
    //由于第i次用的f数据是第i-1次的，为了避免被覆盖，应该j从大到小遍历。
    for(int i = 1; i <= M; i++){
        for(int j = T; j >= t[i]; j--){
            f[j] = max(f[j],f[j-t[i]]+v[i]);
        }
    }


    cout << f[T];

    return 0;
}