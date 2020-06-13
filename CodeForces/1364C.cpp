/*
The key observation is: if for some index i, ai≠ai−1, then bi must be equal to ai−1.
Then we fill the rest of the values with integers missing in a between 0 to n in 
increasing order.
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



int main(){
	fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<int> a(n), b(n, -1), pres(n+1, 0);
	F(a, n);
	if(a[0] == 1){
		b[0]=0;
		pres[0]=1;
	}
	for(int i=1; i<n; i++){
		if(a[i] != a[i-1]){
			b[i] = a[i-1];
			pres[b[i]]=1;//to store numbers which are present in a
		}
	}
	pres[a[n-1]]=1;//to mark the last number as present
	int pos=0;
	for(int i=0; i<n; i++){
		//if the number is present we move to next number
		while(pres[pos]){
			pos++;
		}
		if(b[i] == -1){
			b[i] = pos++;
		}
	}
	P(b, n);
}