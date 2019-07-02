#include<bits/stdc++.h>
#define loop(i,n) for(int i=0; i<n;++i)
#define bloop(i,a,b) for(int i=a;i<=b;++i)
#define MOD 1000000007 
#define MAX int(1e5+5)
#define fio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define vi vector<int>
#define vii vector<pair<int,int>>
#define init(arr,i) memset(arr,i,sizeof(arr))
#define pb emplace_back
#define mod(a,b,c) (a%c)*(b%c)%c
#define max1(v) *max_element(v.begin(),v.end())
#define min1(v) *min_element(v.begin(),v.end())
#define pqi priority_queue<int>
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, MAX, stdin), p1 == p2)) ? EOF : *p1++)
#define rr return 0
//TOJ - 273550YN
char buffer[MAX], *p1, *p2 ;
ull dp[MAX][MAX];
void read(int &x){
		bool neg = false;
		register int c;
		x = 0;
		c = gc();
		if(c=='-'){
			neg=true ;
			c=gc();
		}
		for(;(c>47&&c<58);c=gc())
			x = (x<<1)+ (x<<3)+ c - 48;
		if(neg){
			x*=-1;
		}
} 
ull binomial(ull n, ull k){
		if(k==0){
			return 1 ;
		}
		if(n==0){
			return 0 ;
		}
		if(dp[n][k]!=0){
			return dp[n][k] ;
		}
		dp[n][k] = binomial(n-1,k-1) + binomial(n-1,k) ;
		return dp[n][k] ;
}
signed main(){
		fio;
		ull n,k;
		read(n),read(k) ;
		std::cout<<binomial(n,k) ;
}
