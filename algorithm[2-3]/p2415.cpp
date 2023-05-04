//虽然这个结论是已知的，但假如不知道，可以用分治的思想推导出。
//n个元素的情况：前n-1个元素的情况+最后一个在或不在各一种情况
//因此共2^n个集合，那么每个元素用到2^(n-1)次

#include <bits/stdc++.h>
using namespace std;

int nums[35];
int main(){
    int count = 0;
    long long sum = 0;
    for(; scanf("%d",&nums[count]) != EOF; count++){//不定数目的参数读取
        sum = sum + nums[count];
    }
    sum = sum * (1 << (count-1));//位运算，1<<n表示pow(2,n)
    cout << sum;
    return 0;
}