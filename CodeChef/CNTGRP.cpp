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
const int nax = 1e5 + 1;
const int mod = 1e9+7;
ll a[nax];

ll FastExp(ll a, ll b){
	a %= mod;
	ll res =1;
	while(b>0){
		if(b%2){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b /= 2;
	}
	return res;
}

ll nCr(ll n, ll r){ 
    ll p = 1; 
    if (n - r < r){r = n - r;}
    ll k = 1; 
  
    if (r != 0) { 
        while (r) { 
            p *= n; 
            k *= r; 
            ll m = __gcd(p, k); 
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        } 
    } 
    else{p = 1;}
    return p;
} 


void func(){
	ll n, m;
	cin>>n>>m;
	ll copyIt=m-n+1;
	F(a, n-1);
	sort(a, a+n-1);
	ll dis=0;
	ll freq[n+1] = {0};
	if(m < n-1){
		cout<<0<<"\n";
		return;
	}
	for(int i=0; i<n-1; i++){
		if(a[i] == dis+1){dis++;}
		else if(a[i] > dis+1){
			cout<<0<<"\n";
			return;
		}
		freq[a[i]]++;
	}
	m -= (n-1);
	for(int i=1; i<=n; i++){
		if(freq[i]==0){break;}
		m -= freq[i]-1;
	}
	if(m > 0){
		cout<<0<<"\n";
		return;
	}
	ll ans=1;
	for(int i=2; i<=n; i++){
		if(freq[i]==0){break;}
		ans *= FastExp(freq[i-1],freq[i]);
		ans %= mod;
	}

	ll midConn = 0;
	for(int i=1; i<=n; i++){
		if(freq[i]==0){break;}
		midConn += (freq[i]-1);
	}
	int num = 1;
	while(M!=0) {
		int val = fpow(M , mod-2 , mod);
		int tmp = (open_places) % mod;
		int mul = (val  *  tmp) % mod;
		num  = (num * mul)% mod;
		--M;
		--open_places;
	}	
	ans = (ans * num)%mod;
	ans *= nCr(midConn, copyIt);
	ans %= mod;
	cout<<ans<<"\n";
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}