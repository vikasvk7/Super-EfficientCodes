#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//Vikas' Template
//Example is of a 6 vertex graph having nodes 1....6
//Time taken is O(V+E)
#include<bits/stdc++.h>
#define loop(i,n) for(int i=0; i<n;++i)
#define bloop(i,a,b) for(int i=a;i<=b;++i)
#define MOD 1000000007 
#define MAX int(1e5+5)
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define vi vector<int>
#define vii vector<pair<int,int>>
#define init(arr,i) memset(arr,i,sizeof(arr))
#define pb emplace_back
#define mod(a,b,c) (a%c)*(b%c)%c
#define max1(v) *max_element(v.begin(),v.end())
#define min1(v) *min_element(v.begin(),v.end())
#define endl "\n"
//n&(n-1) hack to count the set bits
#define pqi priority_queue<int>
#define rr return 0
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
bool visited[MAX] ;
vi v[6] ; 
void dfs(int x){
	visited[x] = 1;
	for(auto i : v[x]){ //Check adjacent vertices of x.
		if(visited[i]){
			continue;
		}
		dfs(i);
	}
}
void addEdge(int f,int g){
	v[f].pb(g);
	v[g].pb(f);
}
int main(){
	fio; int components=0;
	memset(visited,0,sizeof(visited));
	
	//1st component
	addEdge(1,2);
	addEdge(2,3);
	addEdge(1,3);
	
	//2nd component
	addEdge(4,5);
	
	//3rd component is isolated 6
	for(int i=1;i<=6;i++){
		if(visited[i]==0){
			dfs(i) ;
			components++ ;
		}
	}
	cout<<"Total Connected Components are "<<components ;
}
