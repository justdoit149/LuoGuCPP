//方案一：间接法，求最小剩余空间——>求最大占据空间
//转换成0-1背包，其中每一个物品的消耗代价相同，价值是其占据空间，上限是V
//这样背包求出Vmax然后再V-Vmax即得答案

//方案二（我的做法）：直接法
//f[i][j]表示只放前i个的情况下、总容量为j时的最小剩余空间。v[i]表示第i个物品占有的空间
//类比背包，可写出状态转移方程：f[i][j] = min(f[i-1][j],f[i-1][j-v[i]])
//其中由于f[i]只和f[i-1]有关，可以将二维数组优化成滚动一维数组，且由[j-v[i]]是减法，故应从后往前
//因此可以得到f[j] = min(f[j],f[j-v[i]])。
//对f[j]的初始化：因为在一开始i=0没有物品的时候，容量为多少剩余量就是多少，所以f[j] = j。

#include <bits/stdc++.h>
using namespace std;

int V,n;
int v[35];
int f[20005];

int main(int argc, char const *argv[])
{
    cin >> V >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int j = 1; j <= V; j++){//初始化f[j]
        f[j] = j;
    }
    for(int i = 1; i <= n; i++){//状态转移
        for(int j = V; j >= v[i]; j--){
            f[j] = min(f[j],f[j-v[i]]);
        }
    }
    cout << f[V];

    return 0;
}
