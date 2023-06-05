#include <bits/stdc++.h>
using namespace std;

int n,temp1,temp2;
int nums[20005][2];
//这个数组存线段的左右端点。
int f[20005][2];
//f[i][0]表示走完第i行且停在第i行的左端点最少用的步数；f[i][1]同理，停在右端点的最少步数。
//到第i行的左顶点结束该行，一定是从第i-1行的两个顶点之一先到第i行的右顶点，再到第i行左顶点，两者取min
//别忘了跨行+1哦。

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> nums[i][0] >> nums[i][1];
    }
    f[0][0] = f[0][1] = -1;//注意合理设置边界
    nums[0][0] = nums[0][1] = 1;
    for(int i = 1; i <= n; i++){
        temp1 = f[i-1][0] + abs(nums[i-1][0]-nums[i][1]) + abs(nums[i][0]-nums[i][1]) + 1;
        temp2 = f[i-1][1] + abs(nums[i-1][1]-nums[i][1]) + abs(nums[i][0]-nums[i][1]) + 1;
        f[i][0] = min(temp1,temp2);
        temp1 = f[i-1][0] + abs(nums[i-1][0]-nums[i][0]) + abs(nums[i][0]-nums[i][1]) + 1;
        temp2 = f[i-1][1] + abs(nums[i-1][1]-nums[i][0]) + abs(nums[i][0]-nums[i][1]) + 1;
        f[i][1] = min(temp1,temp2);
    }
    temp1 = f[n][0] + (n - nums[n][0]);
    temp2 = f[n][1] + (n - nums[n][1]);
    int ans = min(temp1,temp2);
    cout << ans;
    return 0;
}
