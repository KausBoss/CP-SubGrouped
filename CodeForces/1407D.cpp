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
ll n, a[300004], dp[300005];

int main(){
	fastIO
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	dp[0] = 0;
	ll hMaxLast = -1 , hMinLast = -1;
	for(int i=1; i<n; i++){
		dp[i] = dp[i-1] + 1;
		if(hMinLast )
		ll hMax = a[i-1], hMin=a[i-1];
		for(int j=i-2; j>=0; j--){
			if(hMax >= a[i] && hMin <= a[i]) {break;}
			if((hMax < a[j] && hMax < a[i]) || (hMin > a[j] && hMin > a[i]) ){
				dp[i] = min(dp[i], 1 + dp[j]);
			}
			hMax = max(hMax, a[j]);
			hMin = min(hMin, a[j]);

		}
		hMinLast = min(hMin, a[i]);
		hMaxLast = max(hMax, a[i]);
	}
	cout<<dp[n-1];
}