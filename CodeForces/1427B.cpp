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

void func(){
	ll n, k, ans=0;
	string s;
	cin>>n>>k;
	cin>>s;
	bool capF=0;
	ll len=0;
	vector<ll> block;
	for(int i=0; i<n; i++){
		if(s[i] == 'W'){
			ans++;
			if(i >0 && s[i-1]=='W'){ans++;}
			if(len){
				block.pb(len);
				len=0;
			}
			capF = 1;
		}
		else {
			if(capF){len++;}
		}
	}
	if(k==0){
		cout<<ans<<"\n";
		return;
	}
	if(ans == 0){
		cout<<1 + 2*(k-1)<<"\n";
		return;
	}
	sort(block.begin(), block.end());
	int i=0;
	for(i=0; i<block.size() && block[i] <= k; i++){
		ans += 2*(block[i]) + 1;
		k -= block[i];
	}
	if(i < block.size()){
		ans += 2 + 2*(k-1);
		k = 0;
	}
	ll op1=0;
	for(int i=0; i<n;i++){
		if(s[i] == 'W'){break;}
		op1++;
	}
	for(int i=n-1; i>=0; i--){
		if(s[i]=='W'){break;}
		op1++;
	}
	ll d = min(op1, k);
	ans += 2 + 2*(d-1);
	cout<<ans<<"\n";
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