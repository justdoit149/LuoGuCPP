//水
#include <bits/stdc++.h>
using namespace std;

struct num{
    int p,a;
}nums[5005];

bool cmp(num a, num b){
    return a.p < b.p;
}

int main(){
    int n, m, sum = 0 ;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> nums[i].p >> nums[i].a;
    }
    sort(nums,nums+m,cmp);
    for(int i = 0; i < m; i++){
        if(n > nums[i].a){
            sum = sum + nums[i].p * nums[i].a;
            n = n - nums[i].a;
        }else if(n == nums[i].a){
            sum = sum + nums[i].p * nums[i].a;
            break;
        }else{
            sum = sum + nums[i].p * n;
            break;
        }
    }
    cout << sum;

    return 0;
}


//参考代码略