#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include<bits/stdc++.h>
#define loop(i,n) 	for(int i=0; i<n;++i)
#define bloop(i,a,b) 	for(int i=a;i<=b;++i)
#define MOD 		1000000007
#define MAX 		int(1e5+5)
#define fio 		ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll 		long long int
#define ull 		unsigned long long int
#define vi 		vector<int>
#define vii 		vector<pair<int,int>>
#define init(arr,i) 	memset(arr,i,sizeof(arr))
#define pb 		emplace_back
#define mod(a,b,c) 	(a%c)*(b%c)%c
#define max1(v) 	*max_element(v.begin(),v.end())
#define min1(v) 	*min_element(v.begin(),v.end())
#define endl "\n"
//n&(n-1) hack to count the set bits
#define pqi 		priority_queue<int>
#define rr 		return 0
using namespace std;   //Global Array can be of max 10^8 size

template <typename T>
void _read(T &x){
	bool neg = false;
	register int c;
	x = 0;
	c = getchar();
	if(c=='-'){
		neg=true ;
		c=getchar();
	}
	for(;(c>47&&c<58);c=getchar())
		x = (x<<1)+ (x<<3)+ c - 48;
	if(neg){
		x*=-1;
	}
}
//A Dynamic Programming soln for Non-Decreasing Numbers upto 'n'.
//Polynomial Time  --> 10*n
ull count(ull n){
	ull dp[10][n|1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<10;i++){
		dp[i][1]=1 ;
	}
	for(int d=0;d<10;d++){
		for(ull l=2;l<=n;l++){
			for(int x=0;x<=d;x++){
				dp[d][l]+=dp[x][l-1] ; //Make A DP table to Analyse well.
			}
		}
	}
	ull cnt= 0;
	for(int i=0;i<10;i++){
		cnt+=dp[i][n] ;
	}
	return cnt ;
}
int main(){
	ull n;
	cin>>n ;
	cout<<count(n) ;
}

