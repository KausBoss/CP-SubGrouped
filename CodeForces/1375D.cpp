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
	ll n, i, *a, freq[1002]={0};
	cin>>n;
	a = new ll[n];
	set<ll> s;
	vector<ll> ans;
	for(int i=0; i<n; i++){
		cin>>a[i];
		freq[a[i]]++;
	}
	for(ll i=0; i<=n; i++){
		if(freq[i] == 0){
			s.insert(i);
		}
	}
	while(!s.empty()){
		ll ele = *s.begin();
		s.erase(ele);
		if(ele != n){
			ans.pb(ele+1);
			freq[a[ele]]--;
			if(freq[a[ele]] == 0){
				s.insert(a[ele]);
			}
			a[ele] = ele;
			freq[ele]++;
		}
		else{
			for(i = 0; i<n; i++){
				if(a[i] != i){
					s.insert(a[i]);
					freq[a[i]]--;
					freq[n]++;
					a[i] = n;
					ans.pb(i+1);
					break;
				}
			}
		}
	}
	ll h=ans.size();
	cout<<h<<endl;
	P(ans, h);
	// P(a, n);
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;cin>>t;
	while(t--){
		func();
	}
}