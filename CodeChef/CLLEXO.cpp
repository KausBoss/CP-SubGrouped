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



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin>>t;
	while(t--){
		ll n, m;
		cin>>n>>m;
		vector<string> s(n);
		F(s, n);
		string ans="";
		ll j=0, i=0;
		for(j=0; j<m;){
			if(j == 0){
				ans.pb(s[i][j]);
				j++;
			}
			else if(s[i][j] == '#'){
				ans.pb(s[i+1][j-1]);
				i++;
			}
			else if(s[i+1][j-1] == '#'){
				ans.pb(s[i][j]);
				j++;
			}
			else if((s[i][j] <= s[i+1][j-1])){
				ans.pb(s[i][j]);
				j++;
			}
			else{
				ans.pb(s[i+1][j-1]);
				i++;
			}
			if(i==n-1){break;}
		}
		if(i == n-1){

		}
		if(i == n-1){
			while(j < m){
				ans.pb(s[i][j++]);
			}
			cout<<ans<<"\n";
			continue;
		}
		i++;
		while(i<n){
			ans.pb(s[i++][j-1]);
		}

		cout<<ans<<"\n";
	}
}