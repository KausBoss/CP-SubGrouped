/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long
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
#define neg INT_MIN
const int nax = 2e5 + 5;
const int mod = 1e9+7;


int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n, a[nax], ans=0;
	set<pair<ll,ll>> len, segment;
	cin>>n;
	F(a, n);
	ll id=0, length=1;
	for(ll i=1; i<n; i++){
		if(a[i] == a[i-1]){length++;}
		else{
			len.insert({-length, id});
			segment.insert({id, -length});
			length=1;
			id=i;
		}
	}
	//for the last segment
	len.insert({-length, id});
	segment.insert({id, -length});

	while(!len.empty()){
		ans++;
		auto it = len.begin();
		length = it->fi;
		id = it->si;
		len.erase(it);
		// cout<<length<<" "<<id<<endl;

		auto lowseg = segment.lower_bound({id, neg});//neg is INT_MIN to get the first pair whose pair.fi == id
		auto upseg = segment.lower_bound({id, neg});
		upseg++;//to get the id next segment
		//do nothing if the present segment was last or first
		if(lowseg == segment.begin() || upseg == segment.end()){
			segment.erase({id, length});
			continue;
		}
		lowseg--;//the segment just before the present segment
		if(a[lowseg->fi] == a[upseg->fi]){//seg before and seg after have same val
			//we need to combine and create a new segment
			ll newlen = lowseg->si + upseg->si;
			//insertion of new segment
			len.insert({newlen, lowseg->fi});
			segment.insert({lowseg->fi, newlen});
			// deletion of old seg(lowseg and upseg) from segment
			segment.erase(lowseg);
			segment.erase(upseg);
			// deletion of old seg(lowseg and upseg) from len
			len.erase({lowseg->si, lowseg->fi});
			len.erase({upseg->si, upseg->fi});
		}
		segment.erase({id, length});

	}
	cout<<ans;
}