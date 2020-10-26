/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           		long long int
#define vi 				 	vector<int>
#define pb      	     	push_back
#define fi          	 	first
#define si      	     	second
#define pii		 		 	pair<int,int>
#define vii 			 	vector<pair<int,int>>
#define F(a,n)  	     	for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) 		    	for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO      	 	ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n) 	     	for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)     		for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)	     	memset(a, b, sizeof a)
#define matrix(x) 		 	vector<vector<x>>
#define NF(a,n,m)      	    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)		    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  	 	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y) 		(((x) + (y) - 1) / (y))
const int nax = 1e7;
const int mod = 1e9+7;
string s[201];

void func(){
	ll n;
	cin>>n;
	F(s, n);
	if(s[1][0]==s[0][1] && s[n-1][n-2]==s[n-2][n-1] && s[1][0]!=s[n-2][n-1]){
		cout<<0<<endl;
		return;
	}
	if(s[1][0]==s[0][1] && s[n-1][n-2]==s[n-2][n-1] && s[1][0]==s[n-2][n-1]){
		cout<<2<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<2<<" "<<1<<endl;
		return;
	}
	if(s[1][0]==s[0][1] && s[n-1][n-2]!=s[n-2][n-1]){
		cout<<1<<endl;
		if(s[1][0] == s[n-1][n-2]){
			cout<<n<<" "<<n-1<<endl;
			return;
		}
		cout<<n-1<<" "<<n<<endl;
		return;
	}
	if((s[1][0]!=s[0][1] && s[n-1][n-2]==s[n-2][n-1])){
		cout<<1<<endl;
		if(s[1][0] == s[n-1][n-2]){
			cout<<2<<" "<<1<<endl;
			return;
		}
		cout<<1<<" "<<2<<endl;
		return;
	}
	if(s[1][0] == s[n-1][n-2]){
		cout<<2<<endl;
		cout<<n<<" "<<n-1<<endl;
		cout<<1<<" "<<2<<endl;
		return;
	}
	cout<<2<<endl;
	cout<<n<<" "<<n-1<<endl;
	cout<<2<<" "<<1<<endl;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}