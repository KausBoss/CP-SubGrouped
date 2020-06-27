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
const int nax = 2e5 + 2;
const int mod = 1e9+7;

ll a[nax]={0};

void func(){
	memset(a, 0, sizeof(a));
	ll n;cin>>n;bool trip=false;
	for(int i=0; i<n; i++){
		ll temp;
		cin>>temp;
		a[temp]++;
		if(a[temp] >= 3){trip=1;}
	} 
	if(trip){
		cout<<"NO\n";
		return;
	}
	bool cover=false;
	vector<int> des;
	for(int i=1; i<nax; i++){
		if(a[i] == 1){
			cover = 1;
		}
		else if(a[i] == 2){
			cover = false;
			des.pb(i);
		}
	}
	if(!cover){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(int i=1; i<nax; i++){
		if(a[i]){
			cout<<i<<" ";
		}
	}
	for(int i=des.size() - 1; i>=0; i--){
		cout<<des[i]<<" ";
	}
	cout<<endl;
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
		func();
	}
}