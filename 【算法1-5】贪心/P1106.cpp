//错误算法：先删大数，如3214，删1个，应该是214而不是321
//正确算法：寻找高位上的减区间，再将减区间的第一个数删去，后面的跟着补上，最后输出
//如果开头是0，因为0不可能是减区间的第一个数，故它会从后面删，因此可以最后再考虑前导0的问题。
//前面的注释是第一版AC代码，正文部分是最终优化后的（前导0的处理）。


//垃圾代码
// #include <bits/stdc++.h>
// using namespace std;

// char N[256];
// int LEN, k;

// int main(){
//     int index = -1;
//     int l = 0;
//     cin >> N >> k;
//     LEN = strlen(N);
//     for(int i = 0; i < LEN; i++){
//         if(N[i] == '0' && k >= i - l){
//             for(int j = l; j < i; j++){
//                 N[j] = '\0';
//                 k--;
//             }
//             N[i] = '\0';
//             l = i+1; 
//         }
//     }
//     for(int i = 0; i < LEN; i++){
//         if(N[i] > '0'){
//             index = i;
//             break;
//         }
//     }
//     if(index == -1){
//         cout << 0;
//         return 0;
//     }
//     for(int i = 0; index > i && index < LEN; i++, index++){
//         N[i] = N[index];
//         N[index] = '\0';
//     }
//     LEN = strlen(N);
//     while(k>0){
//         bool FIND = false;
//         for(int i = 0; i < LEN; i++){
//             if(N[i] > N[i+1]){
//                 N[i] = '\0';
//                 for(int j = i; j < LEN; j++){
//                     N[j] = N[j+1];
//                 }
//                 k--, LEN--, FIND = true;
//                 break;
//             }
//         }
//         if(FIND == false){
//             break;
//         }
//     }
//     for(int i = 0; i < LEN-k; i++){    
//         cout << N[i];    
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

char N[256];
int LEN, k;

int main(){
    int index = 0;
    cin >> N >> k;
    LEN = strlen(N);    
    while(k>0){  //找递降序列（前>后），找到则删前然后把后面往前补，然后重新从头找
        bool FIND = false;
        for(int i = 0; i < LEN; i++){
            if(N[i] > N[i+1]){
                for(int j = i; j < LEN; j++){
                    N[j] = N[j+1];
                }
                k--, LEN--, FIND = true;
                break;
            }
        }
        if(FIND == false){ //说明已经递增，则从后往前删，也就是输出的时候后面的不输出即可。
            break;
        }
    }
    for(;N[index] == '0'; index++);  //处理前导0
    if(index == LEN){  //处理0
        cout << 0;
    }
    for(int i = index; i < LEN + index - k; i++){//输出
        cout << N[i];    
    }
    return 0;
}

//参考代码：
// #include<iostream>
// #include<string>
// using namespace std;
// int n,k,a[257],rest,t=1,minp,cnt=0;
// bool flag=0;
// string num;
// int main(){
//     cin>>num>>k;
//     n=num.length();
//     for(int i=1;i<=n;++i)a[i]=num[i-1]-'0';
//     rest=n-k;
//     while(cnt<rest){
//         minp=t;
//         for(int i=t;i<=k+t;++i)if(a[minp]>a[i])minp=i;
//         if(a[minp])flag=1;
//         if(flag)cout<<a[minp];
//         k-=minp-t;
//         t=minp+1;
//         cnt++;
//     }
//     if(!flag)cout<<0;
//     return 0;
// }