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
const int nax = 1e7;
const int mod = 1e9+7;
string a, b;
int m, n;

int LCS(int i, int j){
	if(i >= m || j >= n){return 0;}
	string a1 = " " + a.substr(i, a.length() -i);
	string b1 = " " + b.substr(j, b.length() -j);
	cout<<a1<<" "<<b1<<endl;
	vector<vector<int>> dp(a1.length(), vector<int>(b1.length(), 0));
	for(int k=1; k<a1.length(); k++){
		for(int l=1; l<b1.length(); l++){
			if(a1[k] == b1[l]){
				dp[k][l] = dp[k-1][l-1] + 1;
			}
			else{
				dp[k][l] = max(dp[k-1][l], dp[k][l-1]);
			}
		}
	}
	return dp[a1.length() -1][b1.length() - 1];
	return 0;
}

void func(){
	int ans=0;
	cin>>m>>n;
	m--;
	cin>>a>>b;
	int ToatlLCS = LCS(0, 0);
	cout<<ToatlLCS<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<26; j++){
			char ch = 'a' + j;
			for(int k=0; k<n; k++){
				if(b[k] == ch){
					if(LCS(i, k-1) + LCS(i+1, k+1) == ToatlLCS){
						ans++;
					}
				}
			}
		}
	}
	for(int j=0; j<26; j++){
		char ch = 'a' + j;
		for(int k=0; k<n; k++){
			if(b[k] == ch){
				if(LCS(0, k+1) == ToatlLCS){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}