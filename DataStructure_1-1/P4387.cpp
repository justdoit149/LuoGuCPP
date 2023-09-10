//首先要明确，可以是边入栈边出栈，而不是先入完再出（否则直接逆序就行了，是个入门题）
//这样的话需要考虑栈可能是空的，还有入完后没出完剩下的
#include <bits/stdc++.h>
using namespace std;
int q,n,a[100005]={0},b[100005]={0},index_a=1,index_b=1;
stack<int> sta;
int main(){
    cin >> q;
    for(int i = 1; i <= q; i++){
        int temp = sta.size();//这个很有必要，因为每一次pop会让size--
        //因此如果直接把size写到for的条件里会导致j++和size--相当于增加了两次，最后pop次数不足
        for(int j = 1; j <= temp; j++) sta.pop();//初始化    
        index_a = 1, index_b = 1;

        cin >> n;//输入
        for(int j = 1; j <= n; j++) cin >> a[j];
        for(int j = 1; j <= n; j++) cin >> b[j];

        while(index_a <= n){//处理，肯定是a先到n
            if(sta.empty() || sta.top() != b[index_b]){
                sta.push(a[index_a]);
                index_a++;
            }else{
                sta.pop();
                index_b++;
            }
        }
        for(; index_b <= n; index_b++){
            if(sta.top() == b[index_b]) sta.pop();
        }
        // 处理部分的另一种写法
        // for(int j = 1; j <= n; j++){
        //     sta.push(a[j]);
        //     while(sta.top() == b[index_b]){
        //         sta.pop();
        //         index_b++;
        //         if(sta.empty()) break;
        //     }
        // }
        
        if(sta.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}