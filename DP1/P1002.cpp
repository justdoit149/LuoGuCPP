//典型的路径型DP，到每一个点的方式一定是上+左，且需要排除9个点
#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
long long nums[23][23] = {0};
bool check(int x0, int y0){
    if((x - x0 == 1 && y - y0 == 2)
    || (x - x0 == 2 && y - y0 == 1)
    || (x - x0 == -1 && y - y0 == 2)
    || (x - x0 == -2 && y - y0 == 1)
    || (x - x0 == -1 && y - y0 == -2)
    || (x - x0 == -2 && y - y0 == -1)
    || (x - x0 == 1 && y - y0 == -2)
    || (x - x0 == 2 && y - y0 == -1)
    || (x == x0 && y == y0)){//注意别忘了马本身所在的位置也不能走
        return false;
    }else{
        return true;
    }
}
int main(int argc, char const *argv[])
{
    
    cin >> n >> m >> x >> y;
    for(int i = 0; i <= n; i++){//注意是第0行/列开始，且m/n也包含！
        if(i == 0){
            nums[0][0] = (check(0,0) ? 1 : 0);//注意有可能一开始就出问题
            for(int j = 1; j <= m; j++){
                nums[i][j] = (check(i,j) ? nums[i][j-1]: 0);//最左、最上check()为真也不一定是1！！！
            }
        }else{
            nums[i][0] = (check(i,0) ? nums[i-1][0] : 0);
            for(int j = 1; j <= m; j++){
                nums[i][j] = (check(i,j) ? (nums[i-1][j] + nums[i][j-1]) : 0);
            }
        }
    }
    cout << nums[n][m];
    return 0;
}
