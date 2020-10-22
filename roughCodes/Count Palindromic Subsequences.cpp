/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll                   long long int
#define vi                      vector<int>
#define pb                   push_back
#define fi                   first
#define si                   second
#define pii                      pair<int,int>
#define vii                  vector<pair<int,int>>
#define F(a,n)               for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n)                 for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO               ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n)              for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)             for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)             memset(a, b, sizeof a)
#define matrix(x)              vector<vector<x>>
#define NF(a,n,m)              for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)            for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)           for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)          for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y)         (((x) + (y) - 1) / (y))
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
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
    	dp[i][i] = 1;
    }
    int j=1, i=0;
    while(j<n){
    	if(s[i] == s[j]){dp[i][j]=3;}
    	else{dp[i][j]=2;}
    	j++;i++;
    }
    for(int k=2; k<n; k++){
    	j = k, i=0;
    	while(j<n){
    		if(s[i]==s[j]){
    			dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
    		}
    		else{
    			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
    		}
    		i++;j++;
    	}
    }
    cout<<dp[0][n-1];
}