//可以使用哈希表来对数据分类存储
//本题的数据规模为5*10^4，50*2次nlogn是可行的
//所以我的做法：接收数据，然后按照值sort快排（值相同则先出现的在前，也就是下标小的）
//然后把第一个的nums1拷贝到nums2，然后后面的如果后面和前面相同则继续，不同则拷贝
//然后再把nums2按照原来的顺序（也就是之前储存的下标）排序，恢复顺序之后输出即可

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value,index;
}nums1[50005],nums2[50005];
//nums1接收、排序，然后把不重复的放入nums2，然后输出nums2

bool cmp_value(Node x, Node y){
    if(x.value != y.value){
        return x.value <= y.value;
    }else{
        return x.index < y.index;
    }
}
bool cmp_index(Node x, Node y){
    return x.index < y.index;
}


int main(){
    int T,n;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> nums1[j].value;
            nums1[j].index = j;
        }
        sort(nums1+1,nums1+n+1,cmp_value);
        int n2 = 1;
        nums2[1].index = nums1[1].index;
        nums2[1].value = nums1[1].value;
        for(int j = 2; j <= n; j++){
            if(nums1[j].value != nums1[j-1].value){
                n2++;
                nums2[n2].value = nums1[j].value;
                nums2[n2].index = nums1[j].index;
            }
        }
        sort(nums2+1,nums2+n2+1,cmp_index);
        for(int j = 1; j < n2; j++){
            cout << nums2[j].value << ' ';
        }
        cout << nums2[n2].value << '\n';
    }

    return 0;
}