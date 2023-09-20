#include <bits/stdc++.h>
using namespace std;

//不能用char，因为乘法会比较大，会爆掉char的范围。加减法用字符串可以。
int temp[200], ans[200];
void fac(int n);
void sum();

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < 200-1; i++){
        ans[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        fac(i);
        sum();
    }
    int index = 200-2;
    while(index >= 0 && ans[index] == 0){
        index--;
    }
    for(int i = index; i >= 0; i--){
        cout << ans[i];
    }
    return 0;
}

void fac(int n){
    for(int i = 0; i < 200; i++){
        temp[i] = 0;
    }
    int carry = 0;
    temp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 200-1; j++){
            temp[j] = temp[j] * i + carry;
            carry = temp[j] / 10;
            temp[j] = temp[j] % 10;
        }
    }
}

void sum(){
    int carry = 0;
    for(int i = 0; i < 200-1; i++){
        ans[i] = ans[i] + temp[i] + carry;
        carry = ans[i] / 10;
        ans[i] = ans[i] % 10; 
    }
}

