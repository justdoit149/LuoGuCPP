#include <bits/stdc++.h>
using namespace std;

struct num{
    int p;
    bool x;//true表示可用,false表示已分配
} nums[30005];

bool cmp(num a, num b){
    return a.p > b.p;
}

int main(){
    int n,w;
    cin >> w >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i].p;
        nums[i].x = true;
    }
    sort(nums,nums+n,cmp);

    int sum = n;//初始n，每分一组则减一
    for(int i = 0; i < n; i++){//先满足大的
        if(nums[i].x == true){
            int index = n;
            for(int j = n-1; j > i; j--){
                if(nums[i].p + nums[j].p <= w && nums[j].x == true){
                    index = j;
                }else if(nums[i].p + nums[j].p > w){
                    break;
                }
            }
            if(index < n){
                nums[i].x = false;
                nums[index].x = false;
                sum--;
            }
        }else{
            continue;
        }
    }
    cout << sum;

    return 0;
}


// 参考代码：
// #include<cstdio>
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int a[1000000],ans;//定义
// int main(){//过程华丽开始
//     int n,w;//定义
//     scanf("%d",&w);//读入
//     scanf("%d",&n);//读入
//     for(int i=0;i<n;i++)
//         scanf("%d",&a[i]);//读入
//     sort(a,a+n);//调用快排函数sort
//     int z=0,y=n-1;//定义指针（变量）
//     while(z<=y){//开始主要的处理
//         if(a[z]+a[y]<=w){ans++;z++;y--;}//如果能装下，就装
//         else {y--;ans++;}//不能装下，将大的分为单独的一组
//     }
//     printf("%d\n",ans);//输出
//     return 0;
// }