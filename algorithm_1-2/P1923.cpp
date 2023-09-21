#include <bits/stdc++.h>
using namespace std;

int a[5000005];

int main(int argc, char const *argv[])
{
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    nth_element(a,a+k,a+n);
    cout << a[k];
    return 0;
}
