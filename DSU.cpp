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
class Disjoint_Set{
	unordered_map<char,char> parent ;
	unordered_map<char,int> Rank ; //Will store depth of every parent
	public :
	Disjoint_Set(){
		char universe[] = {'a','b','c','d','e'};
		for(auto i : universe){
			parent[i]=i;
			Rank[i]=0;
		}
		parent['d']='b';
		Rank['b']=1;
	}
	char Find(char item){
		if(parent[item]==item){
			return item;
		}
		else{
			return Find(parent[item]);
		}
	}
	void Union(char s1,char s2){
//		parent[s1]=s2;  This will be slower because Find will take then O(depth) time, because tree will be lengthy
//		Improvement :  //Make a RANK map, made it in private section
		if(Rank[s1]>Rank[s2]){
			parent[s2]=s1;
		}
		else if(Rank[s2]>Rank[s1]){
			parent[s1]=s2 ;
		}
		else{
			parent[s1]=s2;
			Rank[s2]++ ;
		}
	}
};
int main(){
	Disjoint_Set ds;
	//In the present graph, {a},{*b-d},{c},{e} are the disjoint sets * is parent
	cout<<ds.Find('c')<<endl ; //c's parent/disjoint set which is c itself
	ds.Union('c','a'); //As rank of both of them is 0, so make anyone parent, here we make a as the parent
	cout<<ds.Find('c'); //Parent of c is a
	ds.Union('a','b'); //a and b's disjoint sets are merged, and as both of them has rank 1, from algo above, b becomes parent
					   //Now a,b,c,d are in the same set with b as the parent.
}

