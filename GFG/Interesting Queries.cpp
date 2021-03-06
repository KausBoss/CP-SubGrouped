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
const int nax = 1e7;
const int mod = 1e9+7;
ll a[10004];

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		ll n, q, k;
		cin>>n>>q>>k;
		F(a, n);
		vector<vector<ll>> freq(1, vector<ll>(1001, 0));
		freq[0][a[0]]++;
		for(int i=1; i<n; i++){
			vector<ll> temp= freq[i-1];
			temp[a[i]]++;
			freq.pb(temp);
		}
		while(q--){
			ll l, r, cnt=0;
			cin>>l>>r;
			l -= 2;r--;
			vector<ll> temp = freq[r];
			if(l >= 0){
				for(int i=1; i<=1000; i++){
					temp[i] -= freq[l][i];
				}
			}
			for(int i=1; i<=1000; i++){
				if(temp[i] >= k){
					cnt++;
				}
			}
			cout<<cnt<<" ";
		}
		cout<<"\n";
	}
}