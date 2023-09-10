//本题用到的的算法和数据结构硬性知识很少，基本上是思维
//关键：首先肯定不能每一次都统计有几种，应该用一个变量记录，每次只考虑变化，大大节省时间
//先进先出，典型的队列
#include <bits/stdc++.h>
using namespace std;

int n,time_index=1,temp,ans=0;
int x[100005] = {0};//由于国籍数范围有限，可以开数组桶计数
struct num{
    int t,k;
}nums[100005];//每一次的t和k放在结构体数组中，而具体的每一个数据放在队列中
queue<int> k;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> nums[i].t >> nums[i].k;//输入
        for(int j = 1; j <= nums[i].k; j++){//将本行数据加入队列，并统计
            cin >> temp;
            if(x[temp] == 0) ans++;//如果原来没有，则国籍数++
            x[temp]++;//桶计数统计
            k.push(temp);
        }
        while(true){//弹出前面超过一天的
            if(nums[i].t - nums[time_index].t >= 86400){
                for(int j = 1; j <= nums[time_index].k; j++){//弹出nums[time_index].k个
                    temp = k.front();
                    k.pop();
                    if(x[temp] == 1) ans--;//如果这个国籍有1个人，则弹出后没人了,ans--
                    x[temp]--;//桶计数统计
                }
                time_index++;//记录一天前的时间对应的nums下标
            }else{
                break;
            }
        }
        cout << ans << '\n';//输出答案
    }

    return 0;
}