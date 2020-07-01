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
ll m, d;
ll dp[ 2001 ][ 2000 ][ 2 ];//dp[pos][odd/even pos][mod][tight]
string s;

ll func(ll pos, ll rem, bool tight){
	//base case
	if(pos == s.length()){
		return rem==0;
	}
	//recursive case
	if(dp[pos][rem][tight] != -1){ return dp[pos][rem][tight];}
	
	ll ans=0;
	ll end = tight ? s[pos]-'0' : 9;
	for(ll i=0; i<=end; i++){
		if((!(pos&1) && i != d) || ((pos&1) && i == d)){
			ans += func(pos+1, ((rem*10)+i)%m, (tight)&(i==end));
		}
		ans %= mod;
	}
	return dp[pos][rem][tight] = ans;
}

bool magic(string a){
	for(int i=0; i<a.length(); i++){
		if(!(i&1) && a[i]-'0' == d){return 0;}
		if((i&1) && a[i]-'0' != d){return 0;}
	}

	ll rem=0;
	for(int i=0; i<a.length(); i++){
		rem = (10*rem + (a[i]-'0'))%m;
	}
	return rem == 0;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a, b;
    cin>>m>>d;
    cin>>a>>b;

    memset(dp, -1, sizeof(dp));
    s = b;
    ll ans = func(0, 0, 1);

    memset(dp, -1, sizeof(dp));
    s = a;
    ans -= func(0, 0, 1);
    ans += mod;
    ans %= mod;
    
    if(magic(a)){ans++;}

    cout<<ans;
}