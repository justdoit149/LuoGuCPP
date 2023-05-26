
//第二种思路：O(nlogn)
//len表示当前的上升序列长度，d表示当前上升序列
//然后从i=1到n遍历来确定d。
//初始i=1时len=1
//每次从后面进来一个a[i]时：
//若a[i] > d[len]则直接加入；
//否则，在d数组里找到第一个大于等于a[i]的数字然后替换掉那个数字。(因为d有序，故这个查找是log级)
//为什么可以这样做呢？因为虽然实际上不能把a[i]真的放到前面，但是这个操作并不会改变len
//因此并不关心这个序列到底是什么。
//就如1,2,7,8,3,4,5，对1,2,7,8先替换掉7变成1,2,3,8，再变成1,2,3,4，最后1,2,3,4,5。
//这样得不到序列是什么，但可以开一个d'数组，每当len++的时候就copy一份到d'里。但这样又是O(n^2)了

#include <bits/stdc++.h>
using namespace std;

int nums[5005],d[5005];
int find(int d[],int l,int r,int x){//闭区间，在d[l]到d[r]里找第一个大于x的数
    //由于第一个大于x的数一定存在且唯一，不需要检验之类的东西，l==r的时候可以直接返回l
    if(l==r) return l;
    int mid = (l+r) / 2;
    if(d[mid] < x){
        return find(d,mid+1,r,x);
    }else{
        return find(d,l,mid,x);
    }
}

int main(){
    int n,ans=1;
    cin >> n;
    cin >> nums[1];
    d[1] = nums[1];
    for(int i = 2; i <= n; i++){
        cin >> nums[i];
        if(nums[i] > d[ans]){
            ans++;
            d[ans] = nums[i];
        }else{
            d[find(d,1,ans,nums[i])] = nums[i];
        }
    }
    cout << ans;
    return 0;
}
