/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           		long long int
#define vi 				 	vector<int>
#define pb      	     	push_back
#define fi          	 	first
#define si      	     	second
#define pii		 		 	pair<int,int>
#define vii 			 	vector<pair<int,int>>
#define F(a,n)  	     	for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) 		    	for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO      	 	ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n) 	     	for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)     		for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)	     	memset(a, b, sizeof a)
#define matrix(x) 		 	vector<vector<x>>
#define NF(a,n,m)      	    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)		    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  	 	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y) 		(((x) + (y) - 1) / (y))
const int nax = 1e7;
const int mod = 1e9+7;


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    if(s[0] == '0'){
    	cout<<0;
    	return 0;
    }
    s = " " + s;
    int n = s.length();
    int dp[n+1] = {1};
    dp[1] = 1;
    for(int i=2; i<n; i++){
    	if(s[i] == '0' && (s[i-1]-'0')*10 + (s[i]-'0') > 26 ){
    		dp[i] = 0;
    	}
    	else if(s[i] == '0'){
    		dp[i] = dp[i-2];
    	}
    	else if( ((s[i-1]-'0')*10 + (s[i]-'0') > 26) || ((s[i-1]-'0')*10 + (s[i]-'0') < 10) ){
    		dp[i] = dp[i-1];
    	}
    	else{
    		dp[i] = dp[i-1] + dp[i-2];
    	}
    }
    // P(dp, n);
    cout<<dp[n-1];	
}