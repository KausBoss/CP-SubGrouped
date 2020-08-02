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
const ll mod = 1e9+7;

void func(){
	ll n, *a;
	cin>>n;
	a = new ll[n];
	F(a, n);
	ll prod=1, maxProd=INT_MIN;
	int maxAns=0, minSoFar=1, maxSoFar=1;
	for(int i=0; i<n; i++){
		if(a[i] > 1){
			maxSoFar = (a[i]*maxSoFar)%mod;
			minSoFar = min(minSoFar*a[i], 1ll);
		}

		else if(a[i] == 0){
			maxSoFar = 1;
			minSoFar = 1;
		}
		else{
			ll temp = maxSoFar;
			maxSoFar = max(minSoFar*a[i], 1ll);
			minSoFar = (temp*a[i])%mod;
		}
		maxAns = max(maxAns, maxSoFar);
	}
	cout<<maxAns<<endl;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}						