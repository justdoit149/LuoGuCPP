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