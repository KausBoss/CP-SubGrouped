/*
*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define mp          make_pair
#define pb          push_back
#define fi          first
#define si          second
#define fastIO      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)      for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)     for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';};
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;

void func(){
	ll n, m;
	cin>>n>>m;
	ll a[n], b[m];
	F(a, n);
	F(b, m);
	int i=n-1, j=0;
	while(i>=0  && j<m){
		if(a[i] > b[j]){
			swap(a[i], b[j]);
		}
		i--;j++;
	}
	sort(a, a+n);
	sort(b, b+m);
	P(a, n);
	P(b, m);
	cout<<endl;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("../inp.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
	#endif
	int t; cin>>t;
	while(t--){
		func();
	}
}