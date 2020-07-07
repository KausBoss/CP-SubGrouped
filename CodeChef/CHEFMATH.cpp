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
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
ll *f= new ll[44];

ll ways(ll x, ll n, ll k){
	//base case
	if(x == 0 && k == 0){return 1;}
	if(x == 0|| k == 0){return 0;}
	if(n<0){return 0;}

	//recursive case
	if(k*f[n] < x){return 0;}
	else{
		if(x >= f[n]){
			return ways(x, n-1, k) + ways(x-f[n], n, k-1);
		}
		else{
			return ways(x, n-1, k);
		}
	}
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    f[0]=1,f[1]=2;
    for(int i=2; i<44; i++){
    	f[i] = f[i-1]+f[i-2];
    }
    ll q, x, k;
    cin>>q;
    while(q--){
    	cin>>x>>k;
    	cout<<ways(x, 43, k)<<endl;
    }
}