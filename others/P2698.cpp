#include <bits/stdc++.h>
using namespace std;

struct Num{
    int x,y;
} nums[100005];

bool cmp(Num x, Num y){
    return x.x < y.x;
}


int main(){
    int N,D;
    cin >> N >> D;
    for(int i = 1; i <= N; i++){
        cin >> nums[i].x >> nums[i].y;
    }
    sort(nums+1,nums+1+N,cmp);
    if(N == 1){
        cout << -1;
        return 0;
    }
    int l = 1, r = 2;
    int W = 1000005;
    while(true){
        if(abs(nums[r].y - nums[l].y) >= D && r > l){
            if(nums[r].x - nums[l].x < W){
                W = nums[r].x - nums[l].x;
            }
            l++;
        }else{
            r++;
        }
        if(r > N){
            break;
        }
    }
    if(W == 1000005){
        cout << -1;
    }else{
        cout << W;
    }


    return 0;
}