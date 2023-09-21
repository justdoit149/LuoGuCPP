#include <bits/stdc++.h>
using namespace std;

struct num{
    string name;
    int x,y,z,i;
}nums[105];


bool cmp(num a, num b){
    if(a.x != b.x){
        return a.x < b.x;
    }else if(a.y != b.y){
        return a.y < b.y;
    }else if(a.z != b.z){
        return a.z < b.z;
    }else{
        return a.i > b.i;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i].name >> nums[i].x >> nums[i].y >> nums[i].z;
        nums[i].i = i;
    }
    sort(nums,nums+n,cmp);
    for(int i = 0; i < n; i++){
        cout << nums[i].name << '\n';
    }
    return 0;
}
