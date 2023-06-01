//完全背包DP。每一个物品可以选择无限次。
//这样状态转移方程是f[i][j] = max(f[i-1][j], f[i][j-t[i]]+v[i])
//即如果不选的话是前i-1个的f[i-1][j]
//如果选的话是f[i][j-t[i]]+v[i]，而f[i][j-t[i]]已经在先前被f[i][j-2t[i]]更新
//从而可以实现第i个选无限次
//经过分析可以看出，整体上和0-1背包代码一样，只是在内层循环遍历的时候是从小到大遍历
//(从大到小遍历：先更新后面的数据，前面的仍然是f[i-1]；从小到大：先更新前面的变成f[i])

#include <bits/stdc++.h>
using namespace std;

int t[10005],v[10005];
long long f[int(1e7)+5];

int main(){
    int T,M;
    cin >> T >> M;
    for(int i = 1;i <= M; i++){
        cin >> t[i] >> v[i];
    }

    for(int i = 1; i <= M; i++){
        for(int j = t[i]; j <= T; j++){
            f[j] = max(f[j],f[j-t[i]]+v[i]);
        }
    }
    cout << f[T];
    return 0;
}