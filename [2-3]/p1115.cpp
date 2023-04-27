// 用一个sum记录当前前缀和，一路累积过去.
// 如果前缀和sum变成了负数，那么下一个数就不需要前面的数了（因为还不如只选它一个）
// 这时把sum置为0，再继续累加。
// 注意数据全为负的情况
// 复杂度O(n)
#include <bits/stdc++.h>
using namespace std;

int nums[200005];
int main(){
    int n, sum = 0, max = 0, Maxnum = -99999;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i]; 
        if(nums[i] > Maxnum){
            Maxnum = nums[i];
        }
        sum = sum + nums[i];
        if(sum < 0){
            sum = 0;
        }else if(sum > max){
            max = sum;
        }
    }
    if(Maxnum < 0){
        cout << Maxnum;
    }else{
        cout << max;
    }
    return 0;
}

//分治的解法，复杂度O(nlogn):
//区间[l,r]里找[i,j]，有三种情况
//ij均在mid左，均在mid右，i在左j在右
//前两种可以分治成更小的区间，第三种可以把前后半段加起来。
//因为第三种一定是i--mid和mid--j，那可以直接遍历穷举来找
//这个思路很常用，二分，找前、找后和前后相连。

// #include <bits/stdc++.h>
// using namespace std;

// int find(int l, int r);

// int nums[200005];
// int main(){
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> nums[i]; 
//     }
//     cout << find(0,n-1);
//     return 0;
// }

// int find(int l, int r){
//     if(l == r){
//         return nums[l];
//     }
//     int mid = (l + r) / 2;
//     int sum1 = 0, sum2 = 0, max1 = -99999, max2 = -99999;
//     for(int i = mid; i >= l; i--){
//         sum1 = sum1 + nums[i];
//         if(sum1 > max1) max1 = sum1;
//     }
//     for(int i = mid+1; i <= r; i++){
//         sum2 = sum2 + nums[i];
//         if(sum2 > max2) max2 = sum2;
//     }
//     int max_l = find(l,mid);
//     int max_r = find(mid+1,r);
//     int max_lr = max1 + max2;

//     if(max_l >= max_r && max_l >= max_lr){
//         return max_l;
//     }else if(max_r >= max_lr){
//         return max_r;
//     }else{
//         return max_lr;
//     }
    
// }