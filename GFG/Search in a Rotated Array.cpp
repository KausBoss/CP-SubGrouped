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
ll a[nax];

ll binSearch(ll a[], ll s, ll e, ll t){
	while(s <= e){
		ll m = (s+e)/2;
		if(a[m] == t){
			return m;
		}
		if(a[m] > t){
			e = m-1;
		}
		else{
			s = m+1;
		}
	}
	return -1;
}

ll func(){
	ll n, t;
	cin>>n;
	F(a, n);
	cin>>t;
	ll s=0, e=n-1, p=n-1;
	if(a[0] < a[n-1]){
		return binSearch(a, 0, n-1, t);
	}
	while(s < e){
		// cout<<s<<" "<<e<<endl;
		ll m = (s+e)/2;
		if(a[m+1] < a[m]){
			p = m;
			break;
		}
		else if (a[m] < a[e]){
			e = m;
		}
		else{
			s = m;
		}
	}
	// cout<<p<<endl;
	ll part1 = binSearch(a, 0, p, t);
	return (part1!=-1) ? part1 : binSearch(a, p+1, n-1, t);
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
		cout<<func()<<"\n";
	}
}