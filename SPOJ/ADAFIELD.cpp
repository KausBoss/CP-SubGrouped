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



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		ll n, m, q;
		cin>>n>>m>>q;
		priority_queue<pair<ll,ll>> verSeg, horSeg;
		set<ll> ver, hor;
		ver.insert(0);
		hor.insert(0);
		ver.insert(n);
		hor.insert(m);
		verSeg.push({n, 0});
		horSeg.push({m, 0});
		while(q--){
			ll dir, cord;
			cin>>dir>>cord;
			if(dir == 0){
				if(ver.find(cord) == ver.end()){
					auto beg1 = ver.lower_bound(cord);
					auto beg2 = beg1--;
					
					verSeg.push({cord - *beg1, *beg1});
					verSeg.push({*beg2 - cord, cord});
					ver.insert(cord);
				}
			}
			else{
				if(hor.find(cord) == hor.end()){
					auto beg1 = hor.lower_bound(cord);
					auto beg2 = beg1--;
					// cout<<dir<<" "<<cord<<" "<<*beg1<<" "<<*beg2<<endl;
					horSeg.push({cord - *beg1, *beg1});
					horSeg.push({*beg2 - cord, cord});
					hor.insert(cord);
				}
			}

			while(verSeg.top().fi != (*(ver.upper_bound(verSeg.top().si)) - (verSeg.top().si))){
				verSeg.pop();
			}
			while(horSeg.top().fi != (*(hor.upper_bound(horSeg.top().si)) - (horSeg.top().si))){
				horSeg.pop();
			}
			cout<<verSeg.top().fi * horSeg.top().fi <<endl;
		}
	}
}