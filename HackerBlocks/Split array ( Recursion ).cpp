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
#define P(a,n)       for(int i=0;i<n;i++){cout<<' '<<a[i];}
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
int n,*a, cnt=0;

int sum(vector<int> v){
	if(v.empty()){return 0;}
	int ans=0;
	for(auto x:v){
		ans += x;
	}
	return ans;
}

void func(int i, vector<int> v1, vector<int> v2){
	//base case
	if(i == n){
		if(sum(v1) == sum(v2)){
			cnt++;
			P(v1, v1.size());
			cout<<" and";
			P(v2, v2.size());
			cout<<endl;
		}
		return;
	}
	//recursive case
	v1.pb(a[i]);
	func(i+1, v1, v2);
	v1.pop_back();
	v2.pb(a[i]);
	func(i+1, v1, v2);
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin>>n;
	a = new int[n];
	F(a, n);
	vector<int> x;
	func(0, x, x);
	cout<<cnt;
}