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
	vector<ll> a, b;
	ll scoreA = 0, scoreB = 0;
	ll n; cin>>n;
	ll last;
	
	while(n--){
		ll temp; cin>>temp;
		if(n == 0){last = temp;}
		if(temp > 0){
			scoreA += temp; 
			a.pb(temp);
		}
		else{
			scoreB += -temp;
			b.pb(-temp);
		}
	}

	if(scoreA != scoreB){
		if(scoreA > scoreB){
			cout<<"first";
		}
		else{
			cout<<"second";
		}
		return 0;
	}

	for(int i=0; i<a.size() && i<b.size(); i++){
		if(a[i] > b[i]){
			cout<<"first";
			return 0;
		}
		else if(a[i] < b[i]){
			cout<<"second";
			return 0;
		}
	}
	if(a.size() != b.size()){
		if(a.size() > b.size()){
			cout<<"first";
		}
		else{
			cout<<"second";
		}
		return 0;
	}

	if(last > 0){
		cout<<"first";
	}
	else{
		cout<<"second";
	}
}