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

struct compy{
	bool operator()(pair<ll,pair<ll,ll>> a, pair<ll,pair<ll,ll>> b){
		if(a.fi == b.fi){
			return a.si.fi < b.si.fi;
		}
		return a.fi > b.fi;
	}
};

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin>>n;
	ll *a = new ll[n];
	F(a, n);
	ll leftId=0, size=1;
	priority_queue<pair<ll,pair<ll, ll>>, vector<pair<ll,pair<ll, ll>>>, compy> pq;
	set<pair<ll, pair<ll, ll>>> s;
	for(ll i=1; i<n; i++){
		if(a[i] != a[i-1]){
			pq.push({size, {leftId, a[i-1]}});
			set.insert({leftId,{size, a[i-1]}});
			leftId = i;
			size = 1;
		}
		else{
			size++;
		}
	}
	if(a[n-1] == a[n-2]){
		pq.push({size, {leftId, a[n-1]}});
		set.insert({leftId,{size, a[n-1]}});
	}
	ll ans =0;
	while(!s.empty()){
		pair<ll,ll> cur = pq.top();
		pq.pop();
		auto fd = s.find({cur.si.fi, {cur.fi, cur.si.si}});
		if(fd != s.end()){
			
		}

	}

}