//本题是典型的DP找最优路径，每一步不一定是最优，不能简单贪心
//若是枚举的话是指数级复杂度，不可取
//下面是DP思路：
//到达每一个点的上一步可能性是有限的（只有从左上和从右上两种）
//因此可以每一个位置的最优，是看它上一步左边和右边哪个更优，也就是把n转换为n-1
//可以在每一个位置存储当前位置的最优总值。
//这样，从上到下、从左到右遍历每一个，把每一个的位置缓存为(左上缓存，右上缓存)+当前值即可
//初始的起点的缓存值为起点的当前值。
//这样遍历一遍所有数据即可解决。

#include <bits/stdc++.h>
#define N 1005
using namespace std;


struct Num{
    int x;
}nums[N][N];

int max(int a,int b){
    return a >= b ? a : b;
}

int main(){
    int r;
    cin >> r;
    nums[1][0].x = 0;
    scanf("%d",&nums[1][1].x);
    nums[1][2].x = 0;
    for(int i = 2; i <= r; i++){
        nums[i][0].x = 0;
        for(int j = 1; j <= i; j++){
            scanf("%d",&nums[i][j].x);
            nums[i][j].x += max(nums[i-1][j-1].x,nums[i-1][j].x);
        }
        nums[i][i+1].x = 0;
    }
    int ans = 0;
    for(int i = 1; i <= r; i++){
        if(nums[r][i].x > ans){
            ans = nums[r][i].x;
        }
    }
    cout << ans;
    return 0;
}