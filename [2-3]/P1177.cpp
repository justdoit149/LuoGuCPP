#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

void quickSort(int a[], int l, int r){
    int mid = a[(l+r)/2];
    int i = l, j = r;
    do{
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++, j--;
        }
    }while(i<=j);//最终i、j到一起，左边的小于等于mid，右边的大于等于mid，然后进一步向下递归。
    if(l<j) quickSort(a,l,j);//如果l>=j也就说明ij已经到最左侧，左边没东西了，只对右边递归即可
    if(i<r) quickSort(a,i,r);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quickSort(a,0,n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}