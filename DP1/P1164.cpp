//状态转移：前i个、花j元记为Ms[i][j]
//则Ms[i][j] = Ms[i-1][j] + Ms[i-1][j-a[i]]
//即：不用这一个+用这一个。
//注意：由于i~i-1因此内层循环反向
//注意。M[0] == 1，即什么都不选。
#include <bits/stdc++.h>
using namespace std;
int Ms[11005] = {1};//初始M[0] = 1,后面的M[i] = 0
int a[105];
int main(int argc, char const *argv[]){
    int N,M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        for(int j = M; j >= a[i]; j--){
            Ms[j] = Ms[j] + Ms[j-a[i]];
        }
        
    }
    cout << Ms[M];
    return 0;
}
