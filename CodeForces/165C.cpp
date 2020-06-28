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



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	// sum[0] = 1 initially cause null string has sum == 0
	ll k, n, cnt =0, ans=0;
	cin>>k;
	string s;
	cin>>s;
	n = s.length();
	vector<ll> sum(1e6 + 1, 0);
	//sum array denotes number of places from 0 to x where sum is equal to i
	//for eg sum[3] denotes number of positions where sum == 3 btw 0 to any index
	sum[0] = 1; //this is because null string also has 0 ones
	for(ll i=0; i<n; i++){
		//cnt denotes number of 1 that have occured from starting of the string
		cnt += s[i] - '0';
		if(cnt >= k){
			ans += sum[cnt - k];
		}
		sum[cnt]++;
	}
	cout<<ans;
}