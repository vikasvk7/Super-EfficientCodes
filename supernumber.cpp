#include<bits/stdc++.h>
using namespace std;
int m=10;
void solve(int divisor, string s){
	if(divisor == m+1){
		exit(0);
	}
	
	for(int i=0;i<=9;i++){
		s.append(to_string(i));
		if(stoll(s) % divisor == 0){
			cout<<s<<" ";
			solve(divisor+1,s);
		}
		s.pop_back() ;
	}
}
int main(){
	cout<<1<<" ";
	solve(2,"1");
}
