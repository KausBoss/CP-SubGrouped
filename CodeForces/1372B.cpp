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
const ll nax = 1e9 + 100;
const int mod = 1e9+7;
vector<ll> prime;

void PrimeSieve(ll n){
	vector<bool> Pr(n+1, 1);
	for(ll i=3; i*i<=n; i+=2){//not checking for 2 as we know all even no. are not prime
		if(Pr[i]){
			for(ll j=3; i*j<=n; j+=2){
				Pr[i*j]=0;
			}
		}
	}
	prime.pb(2); 
	//cout<<2<<" ";//doing manually for 2
	for(ll i=3; i<=n; i+=2){
		if(Pr[i]){
			//cout<<i<<endl;
			prime.pb(i);
		}
	}
	return;
}

void func(){
	ll n;
	cin>>n;
	if(n%2 == 0){
		cout<<n/2<<" "<<n/2<<endl;
		return;
	}
	for(ll i=1; i<prime.size(); i++){
		if(n%prime[i] == 0){
			ll dem = n/prime[i];
			cout<<dem<<" "<<(prime[i]-1)*dem<<endl;
			return;
		}
	}
	cout<<1<<" "<<n-1<<endl;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    PrimeSieve((ll)1e5 +1);
	ll t;cin>>t;
	while(t--){
		func();
	}
}