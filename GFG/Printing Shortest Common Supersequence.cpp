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

void func(){
	string a, b;
	cin>>a>>b;
	int n=a.length(), m=b.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] =  1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			dp[i][j] = i + j - dp[i][j];
		}
	}
	int i=n, j=m;
	string ans="";
	while (i > 0 && j > 0){ 
        if (a[i - 1] == b[j - 1]){ 
            ans.push_back(a[i - 1]);  
            i--; j--; 
        } 
     	else if (dp[i - 1][j] > dp[i][j - 1]){ 
            ans.push_back(b[j - 1]);  
            j--;
        } 
        else{  
            ans.push_back(a[i - 1]); 
            i--;
        } 
    } 
	while(i>0){
		ans.pb(a[i-1]);
		i--;
	}
	while(j>0){
		ans.pb(b[j-1]);
		j--;
	}
	reverse(ans.begin(), ans.end());
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