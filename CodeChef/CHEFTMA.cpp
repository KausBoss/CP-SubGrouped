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

bool desc(ll a, ll b){
	return a > b;
}

void func(){
	ll n, k, m, *a, *b;
	cin>>n>>m>>k;
	a = new ll[n];
	F(a, n);
	b = new ll[n];
	F(b, n);
	vector<ll> left, buttons(m+k);
	for(ll i=0; i<n; i++){
		left.pb(a[i] - b[i]);
	}
	F(buttons, m + k);
	sort(left.begin(), left.end(), desc);
	sort(buttons.begin(), buttons.end(), desc);
	ll i=0, j=0, ans=0;
	while(i<left.size() && j<buttons.size()){
		if(left[i] >= buttons[j]){
			left[i++] -= buttons[j++];
		}
		else{
			j++;
		}
	}
	for(auto x:left){ans += x;}
	cout<<ans<<endl;
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
		func();
	}
}