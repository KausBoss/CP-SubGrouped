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
int n, h, l, r;
int *a;
int dp[2001][2001];

int func(int i, int curr_time){
	//base case
	if(i == n){
		return 0;
	}
	//recursive case
	if(dp[i][curr_time] != -1){ return dp[i][curr_time];}
	int time1 = (curr_time + a[i]) % h;
	int time2 = (curr_time + a[i] - 1) % h;

	int op1 = (time1>=l && time1<=r) + func(i+1, time1);
	int op2 = (time2>=l && time2<=r) + func(i+1, time2);

	return dp[i][curr_time] = max(op1, op2);
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));
	cin>>n>>h>>l>>r;
	a = new int[n];
	F(a, n);
	cout<<func(0, 0);
}