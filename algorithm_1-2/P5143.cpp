#include <bits/stdc++.h>
using namespace std;

struct num{
    int x,y,z;
}nums[50005];

//�Զ�ά���鲻��cmp(int a[], int b[])��������Ϊ��ά������ֻ�ܽ�������ָ��ָ���Ԫ��
//��һ��ָ��ָ���������Ϊ��const�����ܽ�����
//���Դ�����̬�Ķ�ά���飬���������ñȽϺ��������򡣼�int **nums = new int*[3];
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
