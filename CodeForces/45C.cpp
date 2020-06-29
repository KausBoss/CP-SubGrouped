/*
use a set to store indeces which are available
use priority_queue to store pairs in order of decreasing difference
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
	ll n, *a, Bcnt=0, Gcnt=0, less;
	string S;
	cin>>n;
	cin>>S;
	a = new ll[n];
	F(a, n);
	priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pq;
	set<ll> s;
	for(ll i=0; i<n-1; i++){
		if(S[i] != S[i+1]){
			pq.push({ abs(a[i]-a[i+1]), { i, i+1 }});
		}
		if(S[i] == 'B'){Bcnt++;}
		else{Gcnt++;}
	}
	if(S[n-1] == 'B'){Bcnt++;}
	else{Gcnt++;}

	for(ll i=0; i<n; i++){s.insert(i);}

	ll times = min(Bcnt, Gcnt);
	cout<<times<<endl;

	for(int i=0; i<times; i++){
		while(s.find(pq.top().si.fi) == s.end() || s.find(pq.top().si.si) == s.end()){
			// cout<<"queue size "<<pq.size()<<endl;
			pq.pop();
		}

		auto low = s.lower_bound(pq.top().si.fi);
		auto high = s.lower_bound(pq.top().si.si);
		pq.pop();

		cout<<*low + 1<<" "<<*high + 1<<endl;
		auto test = high;
		test++;

		if(low != s.begin() && test != s.end()){
			auto newLow = low;
			newLow--;
			if(S[*newLow] != S[*test]){
				// cout<<"inserting "<<*newLow<<" "<<*test<<endl;
				pq.push({abs(a[*newLow] - a[*test]), {*newLow, *test }});
			}
		}
		s.erase(low);
		s.erase(high);
	}
}