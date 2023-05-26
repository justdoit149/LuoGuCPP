// //最长上升子序列的第一种思路：
// //以第i个为结尾的最长子序列，一定是以前i-1个中的第j个结尾、且第j个小于第i个数的序列里最长的。
// //因此状态转移方程为：f(i) = max(f(j)+1)，其中1<=j<i且nums[j]<nums[i]
// //时间复杂度O(n^2)
// #include <bits/stdc++.h>
// using namespace std;

// int nums[5005];
// struct List{
//     int len;//表示子序列长度
//     int num;//表示上一个数字是多少
//     //好像lists[i].num就是nums[i]，多此一举了……
// }lists[5005];

// int main(){
//     int n,ans=0;
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> nums[i];
//         //边读取边处理，读取第i个后遍历前i-1个然后确定第i个，并及时更新最后的ans
//         int temp_len = 0;
//         for(int j = 1; j < i; j++){
//             if(lists[j].len > temp_len && lists[j].num < nums[i]){
//                 temp_len = lists[j].len;
//             }
//         }
//         lists[i].len = temp_len + 1;
//         lists[i].num = nums[i];
//         if(lists[i].len > ans){
//             ans = lists[i].len;
//         }
//     }
//     cout << ans;
//     return 0;
// }


// //以下是OI-wiki给的代码片段，
// int a[MAXN], d[MAXN];
// int dp() {
//   d[1] = 1;
//   int ans = 1;
//   for (int i = 2; i <= n; i++) {
//     d[i] = 1;
//     for (int j = 1; j < i; j++)
//       if (a[j] <= a[i]) {
//         d[i] = max(d[i], d[j] + 1);
//         ans = max(ans, d[i]);
//       }
//   }
//   return ans;
// }


//第二种思路：O(nlogn)
//len表示当前的上升序列长度，d表示当前上升序列
//然后从i=1到n遍历来确定d。
//初始i=1时len=1
//每次从后面进来一个a[i]时：
//若a[i] > d[len]则直接加入；
//否则，在d数组里找到第一个大于等于a[i]的数字然后替换掉那个数字。(因为d有序，故这个查找是log级)
//为什么可以这样做呢？因为虽然实际上不能把a[i]真的放到前面，但是这个操作并不会改变len
//因此并不关心这个序列到底是什么。
//就如1,2,7,8,3,4,5，对1,2,7,8先替换掉7变成1,2,3,8，再变成1,2,3,4，最后1,2,3,4,5。
//这样得不到序列是什么，但可以开一个d'数组，每当len++的时候就copy一份到d'里。但这样又是O(n^2)了

#include <bits/stdc++.h>
using namespace std;

int nums[5005],d[5005];
int find(int d[],int l,int r,int x){//闭区间，在d[l]到d[r]里找第一个大于x的数
    //由于第一个大于x的数一定存在且唯一，不需要检验之类的东西，l==r的时候可以直接返回l
    if(l==r) return l;
    int mid = (l+r) / 2;
    if(d[mid] < x){
        return find(d,mid+1,r,x);
    }else{
        return find(d,l,mid,x);
    }
}

int main(){
    int n,ans=1;
    cin >> n;
    cin >> nums[1];
    d[1] = nums[1];
    for(int i = 2; i <= n; i++){
        cin >> nums[i];
        if(nums[i] > d[ans]){
            ans++;
            d[ans] = nums[i];
        }else{
            d[find(d,1,ans,nums[i])] = nums[i];
        }
    }
    cout << ans;
    return 0;
}
