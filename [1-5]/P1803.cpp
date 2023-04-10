//本题思路：不管开始时间，按照结束时间的先后来排序。同样选择一个参加的情况下，肯定是早结束>=晚结束。
//因此本题贪心方法是先按照结束时间排序，然后L记录结束时间（L初始为0）
//从前到后找nums[i].l >= L的选上（不重叠且下一次结束最早的）
//这样进行完就是全局最优。

#include <bits/stdc++.h>
#define N int(1e6+5)   //1e6+5是double!!!
using namespace std;

struct num{
    int l,r;
}nums[N];

bool cmp(num a, num b){
    return a.r < b.r;
}

int main(){
    int n;
    cin >> n;
    int L = 0, count = 0;
    for(int i = 0; i < n; i++){
        cin >> nums[i].l >> nums[i].r;
    }
    sort(nums, nums+n, cmp);
    for(int i = 0; i < n; i++){
        if(L <= nums[i].l){
            count++;
            L = nums[i].r;
        }
    }
    cout << count;
    return 0;
}



//参考代码：
// #include<bits/stdc++.h>//（万能库）
// struct px{//（定义一个结构体数组，分别储存开始时间和结束时间）
//     int a;//（开始时间）
//     int b;//（结束时间）
// }x[2000000];
// bool cmp(px x,px y){//（不管开始时间，直接按照结束时间排序）
//     return x.b<y.b;
// }
// using namespace std;
// int main(){
//     int n,sum=1,mi;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     cin>>x[i].a>>x[i].b;//（读入数据）
//     sort(x+1,x+n+1,cmp);//（排序）
//     mi=x[1].b;//（无脑记录第一个值）
//     int j=1;
//     while(j<=n)//（未优化的超长循环）
//     {
//         j++;
//         if(x[j].a>=mi) {//（找到符合要求的比赛，记录，参加）
//         sum++;//（计数）
//         mi=x[j].b;}
//     }
//     cout<<sum;//（输出）
//     return 0;
// }