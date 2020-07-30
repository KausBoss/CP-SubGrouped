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
pair<ll, string> dp[19][2][2][2];//dp[digit][tight wrt a][tight wrt b][start of number]
string a, b;

pair<ll, string> func(ll pos, bool ta, bool tb, bool st){
	//base case
	if(pos == a.length()){
		return {1, ""};
	}
	//recursive case
	if(dp[pos][ta][tb][st].fi != -1){return dp[pos][ta][tb][st];}
	ll lb = (ta) ? a[pos]-'0' : 0;
	ll ub = (tb) ? b[pos]-'0' : 9;
	pair<ll, string> ans(-1, "");
	for(ll i=lb; i<=ub; i++){
		ll val = (st==0&&i==0) ? 1 : i;
		auto ret = func(pos+1, ta&(i==lb), tb&(i==ub), st|(i>0));
		if(val*ret.fi > ans.fi){
			ans.fi = val*ret.fi;
			ans.si = (st==0&&i==0) ? ret.si : to_string(val)+ret.si;
		}
	}
	return dp[pos][ta][tb][st] = ans;
}


int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	for(int i=0; i<19; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				for(int l=0; l<2; l++)
					dp[i][j][k][l].fi = -1;

	cin>>a;
	cin>>b;
	while(b.length() > a.length()){
		a = '0' + a;
	}
	cout<<func(0, 1, 1, 0).si;
}