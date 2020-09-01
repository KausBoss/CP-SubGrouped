/*

*/
#include <bits/stdc++.h>

using namespace std;

#define int           long long int
#define vi 			 vector<int>
#define pb           push_back
#define fi           first
#define si           second
#define pii 		 pair<int,int>
#define vii 		 vector<pair<int,int>>
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)     memset(a, b, sizeof a)
#define matrix(x) 	 vector<vector<x>>
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1000003;

int fact(int n){
	int ans=1;
	while(n>1){
		ans *= n;
		ans %= mod;
		n--;
	}
	return ans;
}

void func(){
	string s;
	cin>>s;
	int n = s.length();
	int freq[26]={0};
	int ans=0;
	for(auto x:s){
		freq[x - 'a']++;
		if(freq[x-'a'] > 1){
			cout<<0<<endl;
			return;
		}
	}
	for(int i=0; i<n; i++){
		int small=0;
		for(int j=0;'a'+j < s[i]; j++){small += freq[j];}
		ans += small%mod * fact(n-i-1);
		ans %= mod;
		freq[s[i] - 'a']--;
	}
	cout<<ans+1<<endl;
}

int32_t main(){
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