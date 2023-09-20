#include <bits/stdc++.h>
using namespace std;

int nums[3005] = {0};

int fac(int n, int a);

int main(int argc, char const *argv[])
{
    int t, n, a;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> a;
        cout << fac(n,a) << "\n";
    }
    return 0;
}
int fac(int n, int a){
    for(int i = 0; i < 3005; i++){
        nums[i] = 0;
    }
    int carry = 0, index = 0, ans = 0;
    nums[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3005; j++){
            nums[j] = nums[j] * i + carry;
            carry = nums[j] / 10;
            nums[j] = nums[j] % 10;
        }
    }
    for(int i = 3005 - 1; i >= 0; i--){
        if(nums[i] != 0){
            index = i;
            break;
        }
    }
    for(int i = index; i >= 0; i--){
        if(nums[i] == a){
            ans++;
        }
    }
    return ans;
}
