#include <bits/stdc++.h>
#include <string.h>
using namespace std;

char a[505],b[505],ans[505];

int myMax(int a, int b){
    return (a > b ? a : b);
}
void myStrrev(char str[]){
    int n = strlen(str);
    for(int i = 0; i < n/2; i++){
        char temp = str[i];
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%s%s",a,b);
    myStrrev(a);
    myStrrev(b);
    int carry = 0, temp1 = 0, temp2 = 0;
    for(int i = 0; i < myMax(strlen(a),strlen(b)); i++){
        temp1 = (a[i] >= '0' ? a[i] - '0' : a[i]);
        temp2 = (b[i] >= '0' ? b[i] - '0' : b[i]);
        ans[i] = temp1 + temp2 + carry;
        carry = ans[i] / 10;
        ans[i] = ans[i] % 10 + '0';
    }
    ans[myMax(strlen(a),strlen(b))] = (carry > 0 ? carry + '0' : carry);
    ans[myMax(strlen(a),strlen(b))+1] = '\0';
    myStrrev(ans);
    cout << ans;
    return 0;
}
