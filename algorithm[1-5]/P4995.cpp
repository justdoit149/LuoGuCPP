//思路：直接先跳到最高，然后大到小到大到小……
//注意奇偶

#include <bits/stdc++.h>
using namespace std;

struct num{
    int h;
}nums[305];

bool cmp(num a, num b){
    return a.h > b.h;
}

int main(){
    long long int n, sum = 0; 
    //h[i] < 1e4，则平方后是1e8，n > 20就爆int了！！！
    //注意数据范围！！！！
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i].h;
    }
    sort(nums,nums+n,cmp);
    sum = nums[0].h * nums[0].h;
    for(int i = 0; i < n / 2 ; i++){
        sum = sum + pow(nums[i].h - nums[n-i-1].h, 2) + pow(nums[i+1].h - nums[n-i-1].h, 2);
    }
    cout << sum;

    return 0;
}

// 参考代码：
// #include<bits/stdc++.h>
// using namespace std;
// unsigned long long ans=0;
// int h[330];
// bool sum=0;
// signed main()
// {
// 	int n;
// 	cin>>n;
// 	for (int i=1;i<=n;i++)
// 	{
// 		cin>>h[i];
// 	}
// 	sort(h+1,h+n+1);
// 	int j=0,hpast=0;
// 	for (int i=1;i<=n;i++)
// 	{
// 		j=n-j+sum;
// 		sum=!sum;
// 		ans+=(h[j]-hpast)*(h[j]-hpast);
// 		hpast=h[j];
// 	}
// 	cout<<ans;
// 	return 0;
// }