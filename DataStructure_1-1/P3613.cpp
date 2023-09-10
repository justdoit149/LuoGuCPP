//正确的方法是使用map映射，因为map自己给你排好了序，比如按照(i,j)对排好了序
//这样查找起来就把O(n)变成了O(logn)，整体上也就是O(nlogn)
//到底该怎么用呢，需要学习（）
#include <bits/stdc++.h>
using namespace std;

map <pair<int,int>,int> p;
map <int,int,int,int> q;
int main(){
    int n,q,count=0;
    cin >> n >> q;
    int temp,i,j,k;
    
    for(int t = 1; t <= q; t++){
        scanf("%d",&temp);
        if(temp == 1){
            scanf("%d%d%d",&i,&j,&k);
            p[{i,j}] = k;
        }else if(temp == 2){
            scanf("%d%d",&i,&j);
            printf("%d\n",p[{i,j}]);
            
        }
    }
}


//错误的做法，思路是注意10的5次方次数远小于10的7次方的格子数
//只存输入的这些，找也只在这些里找，找的时候从后往前找（因为可能有更新）
//但是这样是O(n^2)会TLE
// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int i,j,k;
// };

// Node nums[100005];

// int main(){
//     int n,q,count=0;
//     cin >> n >> q;
//     int temp,i,j,k;
//     for(int t = 1; t <= q; t++){     
//         scanf("%d",&temp);
//         if(temp == 1){
//             scanf("%d%d%d",&i,&j,&k);
//             count++;
//             nums[count].i = i;
//             nums[count].j = j;
//             nums[count].k = k;
//         }else if(temp == 2){
//             scanf("%d%d",&i,&j);
//             for(int t1 = count; t1 > 0; t1--){
//                 if(nums[t1].i == i && nums[t1].j == j){
//                     printf("%d\n",nums[t1].k);
//                     break;
//                 }
//             }
//         }
//     }
//     return 0;
// }
