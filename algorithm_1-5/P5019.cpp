//我的思路：找到当前最浅的坑（深x），则填x词，转换为左边+右边+x，从而递归解决，复杂度o(nlogn)
//为什么这样贪心是对的呢？


#include <bits/stdc++.h>
using namespace std;

int nums[100005];

int to_do(int l, int r, int last_min);
int min_index(int l, int r);

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << to_do(0,n-1,0);

    return 0;
}

int to_do(int l, int r, int last_min){
    if(l > r) return 0;
    int index = min_index(l,r);
    return to_do(l,index-1,nums[index]) + to_do(index+1,r,nums[index]) + nums[index] - last_min;

}

int min_index(int l, int r){
    int index = l, min = nums[l];
    for(int i = l; i <= r; i++){
        if(nums[i] < min){
            min = nums[i];
            index = i;
        }
    }
    return index;
}

// 参考代码：
// #include<bits/stdc++.h>
// using namespace std;
// int n,a[100005];
// long long ans=0;
// int main()
// {
// 	cin>>n;
// 	for(int i=1;i<=n;i++)     cin>>a[i];
// 	for(int i=2;i<=n;i++)     if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
// 	cout<<ans+a[1];
// 	return 0;
// }
//若a[i]>a[i-1],计数器sum+=a[i]-a[i-1];复杂度o(n)