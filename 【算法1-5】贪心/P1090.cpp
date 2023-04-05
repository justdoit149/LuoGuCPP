//不断取最小的两堆合并成较大的一堆是最优的
//好像用堆做比较好，但是我现在还不会（雾）
#include <bits/stdc++.h>
using namespace std;

struct num{  //实际上直接用数组然后sort(a,a+n)也可
    int x;
}nums[10005];

bool cmp(num a, num b){
    return a.x > b.x;
}
int main(){
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i].x;
    }
    sort(nums,nums+n,cmp); //先从大到小排好序
    for(;n>=2;n--){
        nums[n-2].x = nums[n-2].x + nums[n-1].x;
        nums[n-1].x = 0;
        sum = sum + nums[n-2].x;
        int temp = nums[n-2].x;  
        int index = n-3;
        for(;index>=0;index--){//把合成后的找到合适的位置插入。不能直接sort，会超时
            if(nums[index].x < temp){
                nums[index+1].x = nums[index].x;
            }else{
                break;
            }
        }
        nums[index+1].x = temp;
    }
    cout << sum;
    return 0;
}


//参考代码：
// #include<bits/stdc++.h>//（万能库）
// using namespace std;
// int a[100000];//(用一个数组来代替队列)
// int main(){
//     int n,sum=0;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];//（读入数据）
//     }
//     sort(a+1,a+n+1);//（初始排序）
//     while(1){//（开始合并循环，其实可以用for代替）
//         int j=1;
//         while(a[j]==0)
//         j++;
//         //（其实这里懒了，当时做的时候用的是sort,可以用别的做法）
//         if(j==n) break;//（此时只存在一个堆，退出循环）
//         else{
//             a[j]+=a[j+1];
//             sum+=a[j];//（i和j 合并成一个果堆，增加所用的力气）
//             for(int l=j+1;l<n;l++){
//                 a[l]=a[l+1];//（将j后面的果堆向前一位）
//             }
//             n--;//（减少一个堆）
//         }
//         for(int l=j;l<n;l++){
//             if(a[l]>a[l+1]){//（为新的堆找到位置）
//                 swap(a[l],a[l+1]);
//             }
//         }
//     }
//     cout<<sum;
//     return 0;
// }