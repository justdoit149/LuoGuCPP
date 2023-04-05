
#include <bits/stdc++.h>
using namespace std;

char N[256];
int LEN, k;

int main(){
    int index = 0;
    cin >> N >> k;
    LEN = strlen(N);    
    while(k>0){
        bool FIND = false;
        for(int i = 0; i < LEN; i++){
            if(N[i] > N[i+1]){
                for(int j = i; j < LEN; j++){
                    N[j] = N[j+1];
                }
                k--, LEN--, FIND = true;
                break;
            }
        }
        if(FIND == false){
            break;
        }
    }
    for(;N[index] == '0'; index++);
    for(int i = index; i < LEN + index - k; i++){    
        cout << N[i];    
    }
    return 0;
}

