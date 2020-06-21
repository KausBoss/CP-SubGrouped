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
	ll n, k;
	cin>>n>>k;
	ll *a = new ll[n];
	F(a, n);
	ll s = 1, e = 1e9 + 1;
	ll ans;
	while(s <= e){
		ll mid = (s + e)/2;
		bool odd = 0, eve = 0;
		ll j = 1;
		for(int i = 0; i < n; i++){
			if(j&1){
				if(a[i] <= mid){
					j++;
				}
			}
			else{
				j++;
			}
			if(j == k + 1){break;}
		}
		// if(mid == 1){cout<<j<<endl;}
		odd = (j == k + 1);
		j = 1;
		for(int i = 0; i < n; i++){
			if(!(j&1)){
				if(a[i] <= mid){
					j++;
				}
			}
			else{
				j++;
			}
			if(j == k + 1){break;}
		}
		eve = (j == k + 1);
		if(odd || eve){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
		// cout<<mid<<" "<<odd<<" "<<eve<<endl;
	}
	cout<<ans;
}