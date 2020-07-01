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
ll dp[19][4][2];
ll l, r;
string s;

ll solve(ll pos, ll cnt, bool tight){
	//base case
	if(pos ==s.length()){
		return 1;
	}
	//recursive case
	if(dp[pos][cnt][tight] != -1){ return dp[pos][cnt][tight];}

	ll ans = 0;
	ll end = (tight) ? (s[pos]-'0') : 9;
	for(ll i=0; i<=end; i++){
		ll cntupd = cnt + (i>0);
		if(cntupd <= 3){
			ans += solve(pos+1, cntupd, tight&(i==end));
		}
	}
	return dp[pos][cnt][tight] = ans;
}


int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;cin>>t;
	while(t--){
		cin>>l>>r;
		memset(dp, -1, sizeof(dp));
		s = to_string(r);
		ll ans = solve(0, 0, 1);

		l--;
		memset(dp, -1, sizeof(dp));
		s = to_string(l);
		ans -= solve(0, 0, 1);
		cout<<ans<<endl;
	}
}