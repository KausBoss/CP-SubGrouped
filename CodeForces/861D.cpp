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

bool comp(string a, string b){
	return a.length() < b.length();
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin>>n;
	vector<string> s[n];
	set<string> un;
	map<string,ll> m;
	string st[n];
	for(ll i=0; i<n; i++){
		cin>>st[i];

		for(int j=0; j<9; j++){
			for(int k=1; k<= 9-j; k++){
				string temp = st[i].substr(j, k);
				un.insert(temp);
			}
		}
		for(auto it=un.begin(); it!= un.end(); it++){
			m[*it]++;
			s[i].pb(*it);
		}
		un.clear();
		sort(s[i].begin(), s[i].end(), comp);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<s[i].size(); j++){
			if(m[s[i][j]] == 1){
				cout<<s[i][j]<<endl;
				break;
			}
		}
	}
}