#include <bits/stdc++.h>
using namespace std;

struct num{
    int x,y,z;
}nums[50005];

//对二维数组不能cmp(int a[], int b[])来排序，因为二维数组它只能交换二重指针指向的元素
//而一重指针指向的数组认为是const，不能交换。
//可以创建动态的二维数组，这样可以用比较函数来排序。即int **nums = new int*[3];
bool cmp(num a, num b){
    return a.z < b.z;
}

int main(int argc, char const *argv[])
{
    int n;
    double ans = 0, x, y, z;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i].x >> nums[i].y >> nums[i].z;
    }
    sort(nums,nums+n,cmp);
    for(int i = 0; i < n - 1; i++){
        x = nums[i+1].x - nums[i].x;
        y = nums[i+1].y - nums[i].y;
        z = nums[i+1].z - nums[i].z;
        ans += sqrt(x*x + y*y + z*z);
    }

    printf("%.3f",ans);
    return 0;
}
