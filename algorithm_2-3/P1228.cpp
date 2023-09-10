//分治思路：
//k的时候，分成4个等大小正方形区域，看公主在哪个区域，比如在右上
//那么就选形状2，填在4个区域中间位置，这样就转换成4个k-1的方块、每个里有一个公主的情况

#include <bits/stdc++.h>
using namespace std;
enum CASE{
    One = 1, Two = 2, Three = 3, Four = 4
};

void Solve(int k, int x, int y, int x1, int y1);

int main(){
    int k,x,y;
    cin >> k >> x >> y;
    Solve(k,x,y,0,0);
    return 0;
}
//x1、y1表示当前方框的左上角坐标（含0,0），用于定位
//x、y表示被用掉的点在当前方框的位置（从1,1开始）
void Solve(int k, int x, int y, int x1, int y1){
    if(k == 0) return;
    int temp = (1 << (k-1));
    if(x > temp && y > temp){
        printf("%d %d %d\n",temp+x1,temp+y1,Four);
        Solve(k-1,temp,temp,x1,y1);
        Solve(k-1,1,temp,temp+x1,y1);
        Solve(k-1,temp,1,x1,temp+y1);
        Solve(k-1,x-temp,y-temp,temp+x1,temp+y1);
    }else if(x <= temp && y > temp){
        printf("%d %d %d\n",temp+x1+1,temp+y1,Two);
        Solve(k-1,temp,temp,x1,y1);
        Solve(k-1,1,temp,temp+x1,y1);
        Solve(k-1,1,1,temp+x1,temp+y1);
        Solve(k-1,x,y-temp,x1,temp+y1);
    }else if(x > temp && y <= temp){
        printf("%d %d %d\n",temp+x1,temp+y1+1,Three);
        Solve(k-1,temp,temp,x1,y1);
        Solve(k-1,temp,1,x1,temp+y1);
        Solve(k-1,1,1,temp+x1,temp+y1);
        Solve(k-1,x-temp,y,temp+x1,y1);
    }else{
        printf("%d %d %d\n",temp+x1+1,temp+y1+1,One);
        Solve(k-1,1,temp,temp+x1,y1);
        Solve(k-1,temp,1,x1,temp+y1);
        Solve(k-1,1,1,temp+x1,temp+y1);
        Solve(k-1,x,y,x1,y1);
    }
}