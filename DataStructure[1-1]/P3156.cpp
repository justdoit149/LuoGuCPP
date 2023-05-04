#include <bits/stdc++.h>
using namespace std;

int nums[2000005];

int main(){
    int n,m,temp;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%d",&nums[i]);
    }
    for(int i = 1; i <= m; i++){
        scanf("%d",&temp);
        printf("%d\n",nums[temp]);
    }

    return 0;
}
