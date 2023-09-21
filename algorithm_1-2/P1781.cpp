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
        //字符数组用strcmp比大小，返回值是int类型，大于0是前面大，小于0是后面大
        //cmp函数返回类型是bool，true的话不交换a,b(a在前b在后)，false的话交换a,b
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
