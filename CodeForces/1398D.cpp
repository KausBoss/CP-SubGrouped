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
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
ll dp[201][201][201];
ll r, g, b;
vector<ll> R, G, B;


ll func(ll rp, ll gp, ll bp){
	//base case
	if((rp==r) + (gp==g) + (bp==b) >= 2){
		return 0;
	}
	//recursive case
	if(dp[rp][gp][bp] != -1){ return dp[rp][gp][bp];}

	if(rp == r){return G[gp]*B[bp] + func(rp, gp+1, bp+1);}
	if(gp == g){return R[rp]*B[bp] + func(rp+1, gp, bp+1);}
	if(bp == b){return R[rp]*G[gp] + func(rp+1, gp+1, bp);}

	ll op1 = R[rp]*G[gp] + func(rp+1, gp+1, bp);
	ll op2 = G[gp]*B[bp] + func(rp, gp+1, bp+1);
	ll op3 = R[rp]*B[bp] + func(rp+1, gp, bp+1);

	return dp[rp][gp][bp] = max(op1, max(op2, op3));
}

bool desc(ll a, ll b){return a>b;}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	cin>>r>>g>>b;
	R.resize(r); G.resize(g); B.resize(b);
	F(R, r); F(G, g); F(B, b);

	sort(R.begin(), R.end(), desc);
	sort(G.begin(), G.end(), desc);
	sort(B.begin(), B.end(), desc);
	cout<<func(0, 0, 0);
}