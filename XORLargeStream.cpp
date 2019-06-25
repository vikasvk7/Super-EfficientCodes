//XOR from 1 to N without any loop.
//Time complexity - O(1)
//Vikas' Template
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#define loop(i,n) for(int i=0; i<n;++i)
#define bloop(i,a,b) for(int i=a ; i<b;++i)
#define MOD 1000000007 
#define fio std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define vi vector<int>
#define vii vector<pair<int,int>>
#define init(arr,i) memset(arr,i,sizeof(arr))
#define pb emplace_back
#define mod(a,b,c) (a%c)*(b%c)%c
#define pqi priority_queue<int>
#define rr return 0
using namespace boost::multiprecision;
//Naive method takes O(n) time, by taking every element one by one and Xoring them.
//But this method takes O(1) time
//It means
int128_t XORuptoN (ull n){
	if(n%4==0) return int128_t(n);
	if(n%4==1) return 1;
	if(n%4==2) return int128_t(n+1);
	if(n%4==3) return 0;
}
int32_t main(){
	fio;
	ull n1 = 5 ; //Answer of 1^2^3^4^5
	ull n2 = 3274856789101156 ; //Answer of 1^2^3^4....^3274856789101156
	std::cout<<XORuptoN(n1)<<endl;
	std::cout<<XORuptoN(n2)<<endl; 
	rr;
}

