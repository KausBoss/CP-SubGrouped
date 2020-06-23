/*
This approach is faster than top down
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
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e5 + 1;
const int mod = 1e9+7;



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, capaciy;
    cin>>n>>capaciy;
    ll *weight = new ll[n+1];
    ll *cost = new ll[n+1];
    ll dp[101][nax];
    memset(dp, 0, sizeof(dp));
    for(ll i=1; i<=n; i++){
    	cin>>weight[i];
    	cin>>cost[i];
    }

    for(ll i=1; i<=n; i++){
    	for(ll j=0; j<=capaciy; j++){
    		ll op1 = dp[i - 1][j];
    		ll op2 = (weight[i] <= j) ? (cost[i] + dp[i-1][j - weight[i]]) : 0;
    		dp[i][j] = max(op1, op2);
    	}
    }

    cout<<dp[n][capaciy];
}