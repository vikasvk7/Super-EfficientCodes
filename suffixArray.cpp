#include<bits/stdc++.h>
using namespace std;

vector<pair<string,int>> suffix;
string suff[6] ;
int index[6] ;
//bool cmp(string a,string b){
//	return a.compare(b);
//}
void search(char *pattern,char *word ,int n){
	int m=strlen(pattern);
	int beg=0 ;
	int end = n-1;
	while(beg<=end){
		int mid= (beg+end)/2;
		int ans = strncmp(pattern,word+index[mid],m);
		if(ans==0){
			cout<<"\nPattern found at index"<<index[mid] ;
			return ;
		}
		if(ans<0) end=mid-1;
		if(ans>0) beg=mid+1;
	}
	cout<<"Not found" ;
}
void buildSuffix(char *word,int n){
	for(int i=0;i<n;i++){
		suffix.push_back(make_pair(word+i,i));
	}
	sort(suffix.begin(),suffix.end());

	for(int i=0;i<n;i++){
		index[i] = suffix[i].second ;
	}
	for(int i=0;i<n;i++){
		suff[i] = suffix[i].first ;
	}
	
	//Indices
	for(auto i : index){
		cout<<i<<" " ;
	}
	cout<<"\n";
	
	//Suffix
	for(auto i : suff){
		cout<<i<<" " ;
	}
}
int main(){
	char word[] = "banana";
	int n=strlen(word) ;
	buildSuffix(word,n);
	char pattern[]= "nan";
	search(pattern,word,n);
}
