/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
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
	ll n, k, *a, temp=0;
	cin>>n>>k;
	a = new ll[n];
	F(a, n);
	ll totalSum=0;
	for(int i=0; i<n; i++){
		totalSum += a[i];
	}
	temp = totalSum;
	totalSum *= k;
	for(int i=0; a[i] <= 0 && i<n; i++){
		totalSum -= a[i];
	}
	for(int i=n-1; a[i] <= 0 && i>=0; i--){
		totalSum -= a[i];
	}
	ll *pre = new ll[n];
	ll *suf = new ll[n];
	ll maxPre=a[0], maxSuf=a[n-1];
	pre[0] = a[0];
	suf[n-1] = a[n-1];
	for(int i=1; i<n; i++){
		pre[i] = pre[i-1] + a[i];
		maxPre = max(maxPre, pre[i]);
	}
	for(int i=n-2; i>=0; i--){
		suf[i] = suf[i+1] + a[i];
		maxSuf = max(maxSuf, suf[i]);
	}
	//kadane's algo
	ll ms=INT_MIN, cs=0;
	for(int i=0; i<n; i++){
		cs += a[i];
		ms = max(ms, cs);
		if(cs < 0){
			cs=0;
		}
	}
	// cout<<"totalSum: "<<totalSum<<endl;
	// cout<<"maxPre , maxSuf: "<<maxPre<<" "<<maxSuf<<endl;
	// cout<<"ms: "<<ms<<endl;
	if(k == 1){
		cout<<ms<<"\n";
		return;
	}
	if(k <= 2){
		cout<<max(totalSum, max(ms, maxPre+maxSuf))<<"\n";
		return;
	}
	temp = (k-2)*temp + maxSuf + maxPre;
	cout<<max(totalSum, max(ms, max(maxPre+maxSuf, temp)))<<"\n";
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin>>t;
	while(t--){
		func();
	}
}