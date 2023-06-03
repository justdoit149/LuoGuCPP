//每一个点的最大距离 = max(四周四个点的最大距离) + 1；
//关键：先算较低的点，对后续较高的点没有影响。
//故将原数据拷贝一份并按照高度排序，并记录下原始坐标方便回去找。
//为了数据处理方便，将棋盘拓展，四周一圈为0，不用讨论边界。
#include <bits/stdc++.h>
using namespace std;
int d[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
const int SIZE = 4;
//不要在代码里讨论，而是事先写好。

struct num{
    int x,y;//原始坐标
    int value;
}nums[10005];//第三维记录上下左右连着几个，包括自身
int Nums[105][105][2] = {0};//[i][j][0]为高度值，[i][j][1]为最大长度
bool cmp1(num a,num b){
    return a.value < b.value;
}

int main(int argc, char const *argv[])
{
    int R,C,ans = 1;
    cin >> R >> C;
    for(int i = 1; i <= R; i++){//棋盘拓展
        for(int j = 1; j <= C; j++){
            cin >> Nums[i][j][0];
            int k = (i-1) * C + j;//注意这个地方是(i-1)，从1开始
            nums[k].value = Nums[i][j][0];
            nums[k].x = i;
            nums[k].y = j;
        }
    }
    sort(nums+1,nums+1+R*C,cmp1);//按照高度排序
    for(int i = 1; i <= R*C; i++){
        int x = nums[i].x, y = nums[i].y;//取出坐标
        int max = Nums[x][y][1];//一开始默认是0
        for(int j = 0; j < SIZE; j++){
            if(Nums[x][y][0]>Nums[x+d[j][0]][y+d[j][1]][0] && Nums[x+d[j][0]][y+d[j][1]][1]>max){
                max = Nums[x+d[j][0]][y+d[j][1]][1];
            }
        }
        Nums[x][y][1] = max + 1;
    }
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(Nums[i][j][1] > ans){
                ans = Nums[i][j][1];//找最大值
            }
        }
    }
    cout << ans;
    return 0;
}
