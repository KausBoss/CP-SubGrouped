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

void func(){
	ll n, *a;
	cin>>n;
	a = new ll[n];
	F(a, n);
	int dikkatF=-1, dikkatR=-1;
	for(int i=0; i<n-1; i++){
		if(a[i] > a[i+1]){
			dikkatF= i;
			break;
		}
	}
	for(int i=n-1; i>0; i--){
		if(a[i] > a[i-1]){
			dikkatR = i-1;
			break;
		}
	}
	if(dikkatR ==-1 || dikkatF == -1){
		cout<<0<<endl;
		return;
	}
	if(dikkatF > dikkatR){
		cout<<0<<endl;
		return;
	}

	if(dikkatF == n-2 || dikkatR == 0){
		cout<<0<<endl;
		return;
	}
	int j=dikkatR;
	while(j >0  && a[j-1] <= a[j]){
		j--;
	}
	cout<<j<<endl;
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