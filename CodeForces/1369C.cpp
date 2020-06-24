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

void func(){
	ll n, k;
	cin>>n>>k;
	ll *a = new ll[n];
	ll *w = new ll[k];
	F(a, n);
	F(w, k);
	sort(a, a + n);
	sort(w, w + k);
	ll j=n-1;
	ll happy = 0;
	for(int i=0; i<k; i++){
		if(w[i] == 1){
			happy += 2*a[j--];
		}
		else{
			break;
		}
	}
	ll p = 0;
	for(ll i = k-1; i>=0 && w[i] > 1; i--){
		happy += a[p];
		int times = w[i] - 1;
		while(times!=0){p++;times--;}
	}
	for(int i=p; i<=j; i++){
		happy += a[i];
	}
	cout<<happy<<endl;

}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--){
		func();
	}
}