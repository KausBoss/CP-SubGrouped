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
int n, ans=0;
bitset<200> col, diaL, diaR;

bool Nqueen(int row){
	//base case
	if(row == n){
		ans++;
		return false;
	}
	//recursive case
	for(int pos=0; pos<n; pos++){
		if(!col[pos] && !diaL[row - pos + n -1 ] && !diaR[row + pos]){
			col[pos] = diaL[row - pos + n] = diaR[row + pos] = 1;
			bool nextPos = Nqueen(row + 1);
			if(nextPos){
				return true;
			}
			col[pos] = diaL[row - pos + n] = diaR[row + pos] = 0;
		}
	}
	return false;
}


int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin>>n;
	Nqueen(0);
	if(ans){
		cout<<"Possible in "<<ans<<" ways";
	}
	else{
		cout<<"Not Possible";
	}
}