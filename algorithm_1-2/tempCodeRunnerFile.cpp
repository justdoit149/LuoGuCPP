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
        return a.score > b.score;
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
