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
	int n, m;
	char pres;
	cin>>n>>m>>pres;
	string s[n];
	F(s, n);

	set<char> sub;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(s[i][j] == pres){
				if(i != 0 && s[i-1][j] != pres && s[i-1][j] != '.'){
					sub.insert(s[i-1][j]);
				}
				if(i != n-1 && s[i+1][j] != pres && s[i+1][j] != '.'){
					sub.insert(s[i+1][j]);
				}
				if(j != 0 && s[i][j-1] != pres && s[i][j-1] != '.'){
					sub.insert(s[i][j-1]);
				}
				if(j != m-1 && s[i][j+1] != pres && s[i][j+1] != '.'){
					sub.insert(s[i][j+1]);
				}
			}
		}
	}
	cout<<sub.size();
}