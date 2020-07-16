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
	int t, n, m, k, i, j;
	string ans="";
	char c;
	cin>>t;
	while(t--){
		cin>>n>>m;
		string s[n];

		vector<vector<bool>> v(n, vector<bool>(m, 0)), v2(n, vector<bool>(m, 0));

		F(s, n);

		v[n-1][m-1]=1;

		for(k=n+m-3; k>=0; k--){
			for(i=max(0, k-(m-1)); i<n && i<=k; i++){
				j=k-i;

				if(s[i][j]!='#' && i+1<n && v[i+1][j]){
					v[i][j]=1;
				}
				else if(s[i][j]!='#' && j+1<m && v[i][j+1]){
					v[i][j]=1;
				}
			}
		}

		v2[0][0]=1;
		ans="";
		for(k=1; k<n+m-1; k++){
			c='z';
			for(i=max(0, k-(m-1)); i<n && i<=k; i++){
				j=k-i;
				if(i>0 && v2[i-1][j] && v[i][j]){
					c=min(c, s[i][j]);
				}
				else if(j>0 && v2[i][j-1] && v[i][j]){
					c=min(c, s[i][j]);
				}
			}
			ans += c;
			for(i=max(0, k-(m-1)); i<n && i<=k; i++){
				j=k-i;
				if(i>0 &&v2[i-1][j] && v[i][j] && c==s[i][j]){
					v2[i][j]=1;
				}
				else if(j>0 && v2[i][j-1] && v[i][j] && c==s[i][j]){
					v2[i][j]=1;
				}
			}
		}
		cout<<ans<<"\n";
	}
}