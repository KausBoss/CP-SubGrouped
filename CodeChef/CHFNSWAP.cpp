/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long long int
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
#define ceil_div(x, y) (((x) + (y) - 1) / (y))
const int nax = 1e7;
const int mod = 1e9+7;

ll sum(ll n){
	return ( n*(n+1) ) / 2;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		ll n;
		bool equal = 0;
		cin>>n;
		ll total = sum(n);
		if(total&1){
			cout<<0<<"\n";
			continue;
		}
		ll bench = total/2;
		ll s = 1, e = n - 1;
		ll end ;
		while(s <= e){
			ll mid = (s+e)/2;

			if(sum(mid) == bench){
				end = mid;
				equal = 1;
				break;
			}
			else if(sum(mid) < bench){
				end = mid;
				s = mid + 1;
			}
			else{
				e = mid - 1;
			}
		}
		ll ans=n-end;
		ll i = end;
		if(equal){
			ans += (i*(i-1))/2 + (n-i)*(n-i-1)/2;
		}
		cout<<ans<<"\n";
	}
}