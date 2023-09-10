#include <bits/stdc++.h>
//万能头文件，包含几乎所有可能用到的东西，但一般仅比赛使用，工程上不推荐。
int main(){
    int N,T;
    int m[105] = {0}, v[105] = {0};
    double per_value[105] = {0};     //同一个元素的多个信息，最好用结构体。用一堆数组比较乱
    double sum_value = 0;
    scanf("%d%d",&N,&T);
    for(int i = 0; i < N; i++){
        scanf("%d%d",&m[i],&v[i]);
        per_value[i] = v[i] * 1.0 / m[i];  //遇到除法，注意类型转换
    }
    while(T > 0){
        double max_value = 0;
        int max_index = 0;
        for(int i = 0; i < N; i++){    //贪心，每一步的局部最大就是全局最大
            if(per_value[i] > max_value){
                max_index = i;
                max_value = per_value[i];
            }
        }
        //排序这一部分可以用sort来排。见下面的参考代码。
        if(max_value == 0){
            break;
        }
        if(m[max_index] < T){
            T = T - m[max_index];
            sum_value = sum_value + v[max_index];
        }else{
            sum_value = sum_value + per_value[max_index] * T;
            T = 0;
        }
        per_value[max_index] = 0;  //每循环一次之后就把这一轮的maxvalue清零，避免反复用它。
    }
    printf("%.2f",sum_value);


    return 0;
}




// 参考代码：
// #include<bits/stdc++.h> 
// using namespace std;
// struct node{//定义结构体 
//     double w;//重量 
//     double v;//价值 
//     double p;//性价比 
// }a[105];
// int n;
// double sum,c;
// inline bool cmp(node a,node b){
//     return a.p >b.p;//性价比从大到小排序 
// }
// int main(){
//     cin>>n>>c;
//     for(register int i=1;i<=n;++i){
//         cin>>a[i].w>>a[i].v;
//         a[i].p=a[i].v/a[i].w;//性价比=价格/重量 
//     }
//     sort(a+1,a+n+1,cmp);//将性价比排序 
// //使用：从*(a+1)到*(a+n)，按照cmp的方式排序
//     for(register int i=1;i<=n;++i){
//         if(c>=a[i].w){//金币的重量小于或等于背包的承重量
//             c-=a[i].w;//装上该堆金币后背包的剩余承重量 
//             sum+=a[i].v;//金币的价值 
//         }
// 		else{
//             sum+=c*a[i].p;//如果装不下就分割金币 
//             break;
//         }
//     }
//     printf("%.2f",sum);//保留小数点后两位输出
// 	return 0; 
// }
