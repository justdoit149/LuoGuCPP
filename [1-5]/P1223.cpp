#include <bits/stdc++.h>
using namespace std;

int n;
double waittimes = 0;
struct person{
    int index;
    int time;
    int waittime;
} persons[1005];
bool cmp(person a,person b){
    return a.time < b.time;
}
//bool型，两个参数为结构体的元素，按照.time小的在前的顺序来排序

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        persons[i].index = i;
        cin >> persons[i].time;
    }//排好之后下标就改变了，所以还要留一个index位置保存原始下标，便于输出
    sort(persons+1, persons+n+1, cmp);//对结构体数组按照cmp定义的方式进行排序。
    persons[0].waittime = 0;
    persons[0].time = 0;
    for(int i = 1; i <= n; i++){  //方便起见，从1开始
        cout << persons[i].index << " ";
        persons[i].waittime = persons[i-1].waittime + persons[i-1].time;
        waittimes = waittimes + persons[i].waittime; 
    }//注意，求每个人的等待时间是把前面的人的用时相加，总等待时间是把每个人的等待时间相加
    //本质上是知道a[n]数列求s[n]数列，如果直接对s[n]的每项都去for循环求和的话会很慢
    //因此这里运用前缀和的知识，也就是利用s[n] = s[n-1] + a[n]来计算s[n]。
    cout << "\n";
    printf("%.2f",waittimes / n);  //格式化输出结果。
    //第一次写的时候写的int waittimes然后最后是waittimes*1.0/n，结果82分WA了
    //由于double型本身就有误差，所以按照题目要求来写是最保险的。小心！
    return 0;
}



//参考代码：
// #include"iostream"
// #include"cstdio"
// #include"algorithm"//为了用sort快排
// using namespace std;
// struct a  
// {
//  int b,num;//定义结构体a      
// };
// bool cmp(a x,a y)//定义“小于”运算符
// {
//  return x.b<y.b;    
// }
// int main()
// {
//  struct a a[1010];//定义结构体数组
//  int n,i,j;
//  double time=0;
//  cin>>n;    
//  for(i=1;i<=n;i++)   
//   {
//    cin>>a[i].b;
//    a[i].num=i;//序号存起来              
//   } 
//  sort(a+1,a+n+1,cmp);//排序
//   for(i=1;i<=n;i++)
//   {
//    cout<<a[i].num<<" "; //先把简单的做了，输入由小到大的编号
//   }
//   cout<<endl;//要换行
//   for(j=n-1;j>=1;j--) //等待人数的计数器，由n-1开始
//   {
//    i=n-j;//这是个规律，当前最少时间的人序号和要等待的人数之和=n
//    time+=a[i].b*j; //累加                  
//   }
//  printf("%.2lf",time/n);//算平均，保留两位小数
//   return 0; 
// }