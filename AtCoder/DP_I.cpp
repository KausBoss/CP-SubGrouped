/*
dp[i][j] - prob to get min j number of heads if i have i+1 coins
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
const int nax = 1e7;
const int mod = 1e9+7;
ll n;
double p[3000];
double dp[3000][3000];

double func(ll i, ll no_of_heads){
	//base case
	if(no_of_heads == 0){
		return 1;
	}
	if(i == n){
		return 0;
	}
	//recursive case
	if(dp[i][no_of_heads] > -1){ return dp[i][no_of_heads];}

	double tail_curr = (1-p[i])*func(i + 1, no_of_heads);
	double head_curr = p[i]*func(i + 1, no_of_heads-1);

	return dp[i][no_of_heads] = tail_curr + head_curr;

}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(dp, -1.0, sizeof(dp));
	cin>>n;
	F(p, n);
	// no of heads should be between n to ceil((n+1)/2)
	cout<<fixed<<setprecision(10)<<func(0, (n+1)/2);
}