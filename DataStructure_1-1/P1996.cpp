#include <bits/stdc++.h>
using namespace std;

int main(){
    bool nums[105] = {0};
    int n, m,count=0,m0=1;
    cin >> n >> m;
    for(int i = 1; count < n; i = i % n + 1){
        if(m0 < m && nums[i] == 0){
            m0++;
        }else if(m0 == m && nums[i] == 0){
            cout << i << ' ';
            count++;
            m0 = 1;
            nums[i] = 1;
        }
    }
    return 0;
}