//括号序列，和cpl之前的作业题类似，但是这个题题意表述不太明白
//用内置的stack栈来实现，或者用数组模拟栈也可
#include <bits/stdc++.h>
using namespace std;
stack<int> st;
bool ok[101];
int main(){
	string s;
	cin >> s;
	int len = s.length();
	for(int i = 0,k; i < len; i++){
		if(s[i] == ']'){
			if(st.empty()) continue;
			k = st.top();
			if(s[k] == '['){
                st.pop();
				ok[k] = ok[i] = 1;
			}
		}else if(s[i] == ')'){
			if(st.empty()) continue;
			k = st.top();
			if(s[k] == '(') {
                st.pop();
				ok[k] = ok[i] = 1;	
			}
		}else st.push(i);
	}
	for(int i = 0; i < len; i++){
		if(ok[i]) cout << s[i];
		else{
			if(s[i] == '(' || s[i] == ')') cout << "()";
			else cout << "[]";
		}
	}
	return 0;
}