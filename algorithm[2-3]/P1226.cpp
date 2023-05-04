//快速幂与取余运算

#include <bits/stdc++.h>
using namespace std;

long long quickPowMod(long long a, long long b, long long p){
    if(b==0) return 1;
    long long temp = quickPowMod(a,b/2,p);
    if(b&1){//奇数
        return (((temp * temp) % p) * a) % p;  //这里多个大int相乘会爆ll，因此边乘边模
    }else{
        return (temp * temp) % p;
    }
}

int main(){
    long long a, b, p, s;
    cin >> a >> b >> p;
    s = quickPowMod(a,b,p);
    printf("%d^%d mod %d=%d",a,b,p,s);
    return 0;
}