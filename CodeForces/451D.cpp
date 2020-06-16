/*
when we add a char at odd place, number of odd len good string increase by
number of same char at odd place and number of even len good strings increase
by numer of same char at even place.
when we add char at even place the number of odd len good strings increse by
number of same char at even place and number of even len good string increase by
number of same char at odd places.
also odd goos string is initialised with n(len of string) because each single char
is an odd len palindrome in itself
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
	string s;
	cin>>s;
	int CountAB[2][2] = {{0, 0}, {0, 0}};
	int n = s.length();
	//countodd is initialised with n as each single char is a palindrom of 
	//odd length
	ll CountOdd = n, CountEven = 0;
	for(int i = 0; i < n; i++){
		//if adding a char at odd place
		if((i+1) & 1){
			CountOdd += CountAB[1][s[i] - 'a'];
			CountEven += CountAB[0][s[i] - 'a'];
			CountAB[(i+1) & 1][s[i] - 'a']++;
		}
		//if adding char at even place
		else{
			//now even len palindrome is dependant on odd counts
			//and odd len are dependant on even count
			CountEven += CountAB[1][s[i] - 'a'];
			CountOdd += CountAB[0][s[i] - 'a'];
			CountAB[(i+1) & 1][s[i] - 'a']++;
		}
	}
	cout<<CountEven<<" "<<CountOdd;
}