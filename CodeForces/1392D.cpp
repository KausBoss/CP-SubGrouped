/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
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
const int nax = 2e5 + 1;
const int mod = 1e9+7;

void func(){
	ll n;cin>>n;
	string s;
	cin>>s;
	ll cnt = 0, ans=0;
	char cur = 'Y';
	for(int i=1; i<n; i++){
		if(s[i] != s[i-1]){
			reverse(s.begin(), s.end());
			reverse(s.end() - i, s.end());
			reverse(s.begin(), s.end() - i);
			break;
		}
	}
	// cout<<s<<endl;
	for(int i=0; i<n; i++){
		if(s[i] == cur){
			cnt++;
		}
		else{
			if(cnt >=3){
				ans += floor((double)cnt/3);
			}
			cnt = 1;
			cur = s[i];
		}
	}
	if(cnt >=3){
		ans += floor((double)cnt/3);
		if(cnt == n && n%3){ans++;}
	}
	cout<<ans<<endl;
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