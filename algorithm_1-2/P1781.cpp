#include <bits/stdc++.h>
using namespace std;

struct nums{
    int id;
    char score[105];
}Nums[25];

bool cmp(nums a, nums b){
    if(strlen(a.score) != strlen(b.score)){
        return strlen(a.score) > strlen(b.score);
    }else{
        return strcmp(a.score,b.score) > 0;
        //�ַ�������strcmp�ȴ�С������ֵ��int���ͣ�����0��ǰ���С��0�Ǻ����
        //cmp��������������bool��true�Ļ�������a,b(a��ǰb�ں�)��false�Ļ�����a,b
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> Nums[i].score;
        Nums[i].id = i+1;
    }
    sort(Nums, Nums + n, cmp);
    cout << Nums[0].id << '\n' << Nums[0].score;
    return 0;
}
