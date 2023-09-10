//a[i] * b[i] > b[i+1]则后一个人拿得多
//经过数学推导，a[i] * b[i]越大，越往后放
//数据范围：本题ll也不够，必须高精度！！！（学）
//以下是60分代码

#include <bits/stdc++.h>
using namespace std;

struct num{
    int a,b;
}nums[1005];

bool cmp(num a, num b){
    return a.a * a.b < b.a * b.b;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        cin >> nums[i].a >> nums[i].b;
    }
    sort(nums+1,nums+n+1,cmp);
    long long int sum = nums[0].a, temp = 0, max = 0;
    for(int i = 1; i <= n; i++){
        temp = sum / nums[i].b;
        if(temp > max){
            max = temp;
        }
        sum = sum * nums[i].a;
    }
    cout << max;

    return 0;
}