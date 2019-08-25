#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include<bits/stdc++.h>
#define loop(i,n) for(int i=0; i<n;++i)
#define bloop(i,a,b) for(int i=a;i<=b;++i)
#define MOD 1000000007 
#define MAX int(1e5+5)
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ull unsigned long long int
#define ll long long int
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
ll p=0;
void dfs(ll start,bool vis[200000],vector<ll>Graph[200000])
{	p++ ;
    vis[start]=true;
    for(auto x:Graph[start]){
        if(!vis[x])
        {
            dfs(x,vis,Graph);
        }
    }
}
int main()
{	
	fio ;
    ll t;ll i11=1;
    cin>>t;
    while(t--)
    {	
		ll cc=0;
        p=0;
	    vector<ll>Graph[200000];
		bool vis[200000];
	    ll n,e;
	    cin>>n>>e;
	    for(ll i=1;i<=e;i++){
	        ll x,y;
	        cin>>x>>y;
	        Graph[x].push_back(y);
	        Graph[y].push_back(x);
	    }
	    memset(vis,false,sizeof(vis));
	    ll connected=0;
	    for(ll i=1;i<=n;i++)
	    {
	        if(!vis[i]){
	            p=0;
	            dfs(i,vis,Graph);
	            cc=cc+p-1;
	            connected++;
	        }
	    }
    
	    cc=cc+(connected-1)*2;
	    cout<<"Case #"<<i11<<": ";
	    cout<<cc;
	    i11++;
	    cout<<"\n";
	    }
    
    return 0;
}
