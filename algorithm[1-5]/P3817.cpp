// 当相邻的两盒大于x的时候，应该先吃哪一盒呢？
// 答案：正着遍历，吃后面；反着遍历，吃前面！
//也就是一开始求出sum数组，从前往后遍历，发现一个超x的就把它和后面的一起吃。
//数组多留几个空间，不用单独讨论最后一个元素，可以连带着对n+1也处理了（反正用不到）

#include <bits/stdc++.h>
using namespace std;

long long int num[100005], sum[100005]; 
//注意数据范围：a[i]、x < 1e9，n < 1e5，则SUM就可能爆int，因此需要long long int。

int main(){
    long long int n, x, SUM = 0;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < n-1; i++){
        sum[i] = num[i] + num[i+1];
    }
    for(int i = 0; i < n-1; i++){
        if(sum[i] > x){
            int temp = sum[i] - x;
            SUM = SUM + temp;
            sum[i] = sum[i] - temp;
            sum[i+1] = sum[i+1] - temp;
        }
    }
    cout << SUM;
    return 0;
}


//参考代码
// #include <iostream>
// long long n, x, ans;//没开long long的我第一次得80
// long long caddy[100005];//开long long
// int main()
// {
//     std::cin >> n >> x;//读入
//     for (long long i = 1; i <= n; i++)
//     {
//         std::cin >> caddy[i];
//         if (caddy[i] + caddy[i - 1] > x)//如果需要吃糖
//         {
//             ans += caddy[i] + caddy[i - 1] - x;//算一下吃了多少糖
//             caddy[i] -= caddy[i] + caddy[i - 1] - x;//把吃掉的糖去掉
//         }
//     }
//     std::cout << ans;//输出答案
//     return 0;
// }