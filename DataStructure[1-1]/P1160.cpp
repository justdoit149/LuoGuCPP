//考虑到本题N范围不算大，可以开出100005个空间，而直接用链表的话删除时查找的过程很慢
//因此就开一个大结构体数组，下标表示第i个人，l、r表示其左右的人，以空间换时间
//这样不管插入还是删除都是O(1)，因此整个过程就是O(n)
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int l,r;
}nodes[100005];

void My_insert(int i, int k, int p){
    if(p == 0){
        nodes[i].l = nodes[k].l;
        nodes[k].l = i;
        nodes[nodes[i].l].r = i;
        nodes[i].r = k;
    }else if(p == 1){
        nodes[i].r = nodes[k].r;
        nodes[k].r = i;
        nodes[nodes[i].r].l = i;
        nodes[i].l = k;
    }
}

void My_delete(int x){
    int l = nodes[x].l, r = nodes[x].r;
    if(l != 0) nodes[l].r = r;
    if(r != 0) nodes[r].l = l;
    nodes[x].l = 0;
    nodes[x].r = 0;
}

int main(){
    int N,M;
    cin >> N;
    nodes[1].l = 0;
    nodes[1].r = 0;
    for(int i = 2; i <= N; i++){
        int k,p;
        cin >> k >> p;
        My_insert(i,k,p);
    }
    cin >> M;
    for(int i = 1; i <= M; i++){
        int x;
        cin >> x;
        My_delete(x);
    }
    for(int i = 1; i <= N; i++){
        if(nodes[i].l == 0 && nodes[i].r != 0){
            int temp = i;
            while(temp != 0){
                cout << temp << ' ';
                temp = nodes[temp].r;
            }
            break;
        }
    }
    return 0;
}