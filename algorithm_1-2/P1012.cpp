#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
	return a+b>b+a;
}

int main(int argc, char const *argv[])
{
    int n;
    string nums[25];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    sort(nums,nums+n,cmp);
    for(int i = 0; i < n; i++){
        cout << nums[i];
    }
    return 0;
}
