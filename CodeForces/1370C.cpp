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

string func(){
	string s[2] = {"Ashishgup", "FastestFinger"};
	ll n;
	cin>>n;
	if(n == 1){return s[1];}
	if(n == 2 || n&1){return s[0];}
	int oddDiv=0, PowOf2 = 0;
	while(!(n&1)){
		PowOf2++;
		n /= 2;
	}
	for(ll i = 3; i <= sqrt(n); i += 2){
		while(n%i == 0){
			oddDiv++;
			n /= i;
		}
	}
	if(n > 1){oddDiv++;}

	if(oddDiv == 0){return s[1];}
	return (PowOf2>1) ? s[0] : ((oddDiv > 1) ? s[0] : s[1]);
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
		cout<<func()<<endl;
	}
}