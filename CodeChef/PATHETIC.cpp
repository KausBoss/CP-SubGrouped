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
ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 111};

void func(){
	ll n;
	cin>>n;
	vector<vector<ll>> g(n);
	for(ll i=0; i<n-1; i++){
		ll x, y;
		cin>>x>>y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	ll num[2] = {1, 1};
	for(ll i=0; prime[i]<=n; i++){
		if(i&1 || i==2){	
			num[1] *= prime[i];
		}
		else{
			num[0] *= prime[i];
		}
	}

	vector<ll> ans(n), visited(n, 0);
	queue<pair<ll, bool>> q;
	q.push({0, 0});
	while(!q.empty()){
		auto tp = q.front();
		q.pop();
		ans[tp.fi] = num[tp.si];
		visited[tp.fi]=1;
		for(auto x:g[tp.fi]){
			if(!visited[x]){
				q.push({x, !tp.si});
			}
		}
	}
	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<"\n";
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		func();
	}
}