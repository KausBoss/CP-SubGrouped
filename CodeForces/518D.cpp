/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
#define mp           make_pair
#define pb           push_back
#define fi           first
#define si           second
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
ll n, t;
double ans =0, dp[2001][2001]={0}, p;

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	dp[0][0]=1;
	cin>>n>>p>>t;
	for(int i=1; i<=t; i++){
		for(int j=0; j<=n; j++){
			if(j == n){
				dp[i][j] = p*(dp[i-1][j-1]) + dp[i-1][j];
			}
			else if(j == 0){
				dp[i][j] = (1-p)*dp[i-1][j];
			}
			else{
				dp[i][j] = p*(dp[i-1][j-1]) + (1-p)*(dp[i-1][j]);
			}
		}
	}

	for(int i=0; i<=n; i++){
		ans += i*dp[t][i];
	}
	cout<<fixed<<setprecision(6)<<ans;
}