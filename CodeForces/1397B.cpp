/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
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

void func(){
	ll n;
	cin>>n;
	ll *a = new ll[n];
	F(a, n);
	sort(a, a+n);
	ll sum=0;
	for(int i=0; i<n; i++){
		sum += a[i];
	}
	bool same=0;
	ll c = ceil((double)pow(a[n-1], 1.0/(n-1)));
	ll c1 = floor((double)pow(a[n-1], 1.0/(n-1)));
	if(c1 == c){same=1;c1--;}
	ll ans =0;ll dem=1;
	for(int i=0; i<n; i++){
		ans += abs(dem - a[i]);
		dem *= c;
	}
	ll ans2 =0;dem=1;
	for(int i=0; i<n; i++){
		ans2 += abs(dem - a[i]);
		dem *= c1;
	}
	if(same){
		c++;
		ll ans3 =0;dem=1;
		for(int i=0; i<n; i++){
			ans3 += abs(dem - a[i]);
			dem *= c;
		}
		ans2 = min(ans3, ans2);
	}
	cout<<min(ans,min(ans2, sum-1))<<endl;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;//cin>>t;
	while(t--){
		func();
	}
}