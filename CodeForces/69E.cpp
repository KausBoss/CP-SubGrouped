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
	ll n, k, *a;
	cin>>n>>k;
	a = new ll[n];
	F(a, n);

	map<ll, ll> m;
	priority_queue<ll> pq;

	for(ll i=0; i<n; i++){
		if(m.count(a[i]) == 0){m[a[i]] = 1;}
		else{m[a[i]]++;}
		if(m[a[i]] == 1){
			pq.push(a[i]);
		}
		// cout<<"-----"<<a[i]<<" "<<m[a[i]]<<endl;
		if(i >= k-1){
			while(!pq.empty() && m[pq.top()] != 1){
				//cout<<"popping "<<pq.top()<<endl;
				pq.pop();
			}

			if(pq.empty()){
				cout<<"Nothing\n";
			}
			else{
				cout<<pq.top()<<endl;
			}

			m[a[i+1 - k]]--;
			//cout<<"removing "<<a[i+1 - k]<<" "<<m[a[i+1 - k]]<<endl;
			if(m[a[i+1 - k]] == 1){
				//cout<<"inserting "<<a[i+1 - k]<<" "<<m[a[i+1 - k]]<<endl;
				pq.push(a[i+1 - k]);
			}
		}
	}
}