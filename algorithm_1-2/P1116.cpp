#include <bits/stdc++.h>
using namespace std;

//ʵ�ʾ����������Ŀ��������ð�����򽻻�������
int nums[10005];

int main(int argc, char const *argv[])
{
    int n,ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] > nums[j]){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
