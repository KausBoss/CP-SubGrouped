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
const int nax = 1e6 +1;
const int mod = 1e9+7;

void func(){
	string s;
	cin>>s;
	ll ctMinus = 0, ctPlus=0;
	for(ll i=0; i<s.length(); i++){
		if(s[i] == '+'){ctPlus++;}
		else{ctMinus++;}
	}
	vector<bool> ar(s.length(), 0);
	ll seg =0, cnt =0, ans=0;
	for(ll i=0; i<s.length(); i++){
		if(s[i] == '-'){
			if(seg == 0){
				ar[i] = 1;
				cnt++;
			}
			else{
				seg--;
			}
		}
		else{
			seg++;
		}
	}
	if(seg >= 0){cnt++;}

	// cout<<"here "<<cnt<<endl;

	for(ll i=0; i<s.length(); i++){
		ans += cnt;
		if(ar[i]){
			cnt--;
		}
	}
	cout<<ans<<endl;
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