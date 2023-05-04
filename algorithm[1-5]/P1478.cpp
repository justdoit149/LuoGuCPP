//先从小到大排力气，然后选择从小到大且能够到的。

#include <bits/stdc++.h>
using namespace std;

struct num{
    int x,y;
} nums[5005];

bool cmp(num a, num b){
    return a.y < b.y;
}

int main(){
    int n,s,a,b;
    int count = 0;
    cin >> n >> s >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> nums[i].x >> nums[i].y;
    }
    sort(nums, nums+n, cmp);
    for(int i = 0; i < n; i++){
        if(a + b >= nums[i].x){
            if(s > nums[i].y){
                s = s - nums[i].y;
                count++;
            }else if(s == nums[i].y){
                count++;
                break;
            }else{
                break;
            }
        }else{
            continue;
        }
    }
    cout << count;
    


    return 0;
}




//参考代码：
// #include <bits/stdc++.h>
// using namespace std;
// struct apple{//开个结构体就好哩
//     int x;
//     int y;
// }gi[50005];
// bool cmp(struct apple a,struct apple b)
// {
//     return a.y<b.y;
// }
// int main(){
//     freopen("ii.in","r",stdin);
//     freopen("ii.out","w",stdout);
//     int n,s,a,b,ans=0;
//     cin>>n>>s>>a>>b;
//     for(int i=0;i<n;i++)cin>>gi[i].x>>gi[i].y;
//     sort(gi,n+gi,cmp);
//     for(int i=0;i<n;i++)
//     {
//         if(s-gi[i].y<0)break;
//         if(gi[i].x>a+b)continue;
//         else {s-=gi[i].y;ans++;}
//     }
//     cout<<ans;
//     return 0;
// }