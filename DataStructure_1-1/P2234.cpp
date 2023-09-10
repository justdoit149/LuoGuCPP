//本题数据范围是10^6，直接桶计数，然后找离着最近的
//这样第一次找可能距离是10^6级，但每一次随着新数据插入，原来的数据会越来越密集
//比如插入100个数以后找起来就是10^4级了，这样速度很快（比常规做法的nlogn还快）
#include <bits/stdc++.h>
using namespace std;

bool nums[4000005] = {0};

int main(){
    int n,temp,ans;
    cin >> n;
    cin >> temp;
    ans = temp;
    nums[temp + 2000000] = 1;
    for(int i = 2; i <= n; i++){
        cin >> temp;
        if(nums[temp + 2000000] == 1){
            continue;
        }else{
            nums[temp + 2000000] = 1;
            temp = temp + 2000000;
            for(int j = 1; ; j++){
                if(nums[temp+j] == 1 || nums[temp-j] == 1){
                    ans = ans + j;
                    break;
                }
            }
        }
    }
    cout << ans;



    return 0;
}