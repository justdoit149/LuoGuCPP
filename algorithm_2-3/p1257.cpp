//这题分治法做真的是普及-吗………

#include <bits/stdc++.h>
using namespace std;

long long nums[10005][2];
int main(){
    int n;
    long long d=0,min=pow(10,18);
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d%d",&nums[i][0],&nums[i][1]);
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            d = (nums[i][0] - nums[j][0]) * (nums[i][0] - nums[j][0]) 
              + (nums[i][1] - nums[j][1]) * (nums[i][1] - nums[j][1]);
            //pow比直接算慢，开根号也慢，所以尽可能少用
            if(d < min) min = d;  
        }
    }
    printf("%.4f",sqrt(min));
    // long long int c = 1111111111;
    // long long int d = 1111111111;
    // long long int e = c * c;
    // printf("%lld", e);
    return 0;
}