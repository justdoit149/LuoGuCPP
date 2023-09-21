#include <bits/stdc++.h>
using namespace std;

int nums[1005] = {0};

int main(int argc, char const *argv[])
{
    int n,m,temp;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        scanf("%d",&temp);
        nums[temp]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < nums[i]; j++){
            printf("%d ",i);
        }
    }
    return 0;
}
