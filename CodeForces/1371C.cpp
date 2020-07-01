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

bool func(){
	ll a, b, mn, mx, mne, mxe;
	cin>>a>>b>>mxe>>mne;
	if(a > b){mx = a;mn = b;}
	else{mx = b;mn = a;}

	if(mn + mx < mne + mxe){return 0;}
	if(mn < mne && mxe < (mx - mn)){return 0;}
	if(mn >= mne){return 1;}
	// if(mx >= mxe + mne){return 1;}
	ll tot = mn + mx;
	tot -= mxe;
	if(tot%2 == 0){mx = mn = tot/2;}
	else{
		tot++;
		mn = mx = tot/2;
		mn--;
	}
	if(mn < mne){return 0;}
	return 1;
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
		if(func()){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}