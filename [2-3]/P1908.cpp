//最简单的思路是二重循环,O(n^2),根据500000的数据范围显然会超时
//思考，如何优化呢？考虑将数组一分为二，则逆序一定是三种情况之一
//即左边内部逆序，右边内部逆序，左右之间逆序
//左右内部即为更小的情况，可以分治下去，最终拆成每段长度为1，内部为0
//然后再把小段合并成大段，即使加上左右之间的情况，最小段的左右之间即为稍大段的左右内部
//然后再进一步加上稍大段的左右之间，得到更大段的左右内部
//这样，只需要计算的时候考虑左右之间+递归分治。
//左右之间与左右内部顺序无关，可以把内部排好序再看左右之间，看完了再把整体排好序去看更大的整体
//看左右之间大概就是看某一边的某个位置能插入到另一侧的哪个位置
//这样看来，流程基本上就是归并排序，O(nlogn)


#include <bits/stdc++.h>
using namespace std;
long long int n, sum = 0;
int a[500005],b[500005],c[500005];

void merge(int l1, int r1, int l2, int r2){
    for(int i = l1; i <= r1; i++) b[i-l1] = a[i];
    for(int i = l2; i <= r2; i++) c[i-l2] = a[i];
    int i = 0, j = 0;
    while(i <= r1 - l1 && j <= r2 - l2){
        if(b[i]>c[j]) a[l1 + i + j] = c[j], j++;
        else a[l1 + i + j] = b[i], i++; 
    }
    if(i > r1 - l1){
        for(; j <= r2 - l2; j++) a[l1 + i + j] = c[j];
    }else if(j > r2 - l2){
        for(; i <= r1 - l1; i++) a[l1 + i + j] = b[i];
    }
}
void mergeSort(int l, int r){
    if(l == r) return;
    int mid = (l+r) / 2;
    mergeSort(l,mid);//先分治
    mergeSort(mid+1,r);
    for(int i = l, j = mid+1; i <= mid; i++){
        while(a[i] > a[j] && j <= r) j++;
        sum = sum + j - mid - 1;
    }
    merge(l,mid,mid+1,r);//分治后merge边归并边计数，便于返回后对更大规模段的计数 
}
int main(){
    scanf("%lld",&n); 
    for(int i=0;i<n;i++) //scanf,printf比cin,cout快得多，对于大数组最好是scanf/printf输入输出
    	scanf("%d",&a[i]);
    mergeSort(0,n-1);
    printf("%lld",sum);
    return 0;
    
}

//参考代码：

// #include<cstdio>
// #include<iostream>
// using namespace std;
// int n,a[500010],c[500010];
// long long ans;

// void msort(int b,int e)//归并排序
// {
//     if(b==e)  
// 		return;
//     int mid=(b+e)/2,i=b,j=mid+1,k=b;
//     msort(b,mid),msort(mid+1,e);
//     while(i<=mid&&j<=e)//边归并排序边统计，效率比我高
//     	if(a[i]<=a[j])
//     		c[k++]=a[i++];
//     	else
//     		c[k++]=a[j++],ans+=mid-i+1;//统计答案
//     while(i<=mid)
//     	c[k++]=a[i++];
//     while(j<=e)
//     	c[k++]=a[j++];
//     for(int l=b;l<=e;l++)
//     	a[l]=c[l];
// } 

// int main()
// {
//     scanf("%d",&n); 
//     for(int i=1;i<=n;i++)
//     	scanf("%d",&a[i]);
//     msort(1,n);
//     printf("%lld",ans);
//     for(int i=1;i<=n;i++) //scanf,printf比cin,cout快得多，对于大数组最好是scanf/printf输入输出
//     	printf("%d",a[i]);
//     return 0;
// }