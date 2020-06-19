/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long
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
const int nax = 1e5 + 2;
const int mod = 1e9+7;

bool sorty(pair<ll, pair<ll, ll>> &a, pair<ll, pair<ll, ll>> &b){
	if(a.fi == b.fi){
		return a.si.fi > b.si.fi;
	}
	return a.fi < b.fi;
}



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin>>t;
	while(t--){
		ll n, d;
		cin>>n>>d;
		vector<ll> sad(n), arrive(n), lect(n);
		vector<pair<ll, pair<ll, ll>>> pq;

		for(ll i = 0; i < n; i++){
			cin>>arrive[i]>>lect[i]>>sad[i];
			pq.pb({arrive[i], {sad[i],i}});
		}
		sort(pq.begin(), pq.end(), sorty);
		priority_queue<pair<ll, ll>> candidate;
		ll j = 0; 
		for(ll i = 1; i <= d; i++){
			while(j < n && pq[j].fi == i){
				candidate.push({pq[j].si.fi, pq[j].si.si});
				j++;
			}

			if(candidate.empty()){ continue;}

			pair<ll,ll> today_proff = candidate.top();
			lect[today_proff.si]--;

			if(lect[today_proff.si] == 0){
				candidate.pop();
			}
		}

		ll ans = 0;
		for(ll i=0; i<n; i++){
			ans += (sad[i]*lect[i]);
		}
		cout<<ans<<endl;
	}
}