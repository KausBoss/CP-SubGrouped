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
    ll n, k, Atot=0, Btot=0, com=0;
	priority_queue<ll, vector<ll>, greater<ll>> Awale, Bwale, both;
	priority_queue<ll> Adone, Bdone;
	cin>>n>>k;
	for(ll i=0; i<n; i++){
		ll time, a, b;
		cin>>time>>a>>b;
		if(a && b){
			both.push(time);
			Atot++; Btot++;
		}
		else if(a && !b){
			Awale.push(time);
			Atot++;
		}
		else if(!a && b){
			Bwale.push(time);
			Btot++;
		}
	}
	//checking for possible or not
	if(Atot <k || Btot < k){
		cout<<-1; return 0;
	}

	while(!Awale.empty() && Adone.size() < k){
		Adone.push(Awale.top());
		Awale.pop();
	}

	while(!Bwale.empty() && Bdone.size() < k){
		Bdone.push(Bwale.top());
		Bwale.pop();
	}

	ll extra = max(k - Adone.size(), k - Bdone.size());

	while(extra--){
		com += both.top();

		if(Bdone.size() > Adone.size()){
			Bdone.pop();
		}
		else if(Adone.size() > Bdone.size()){
			Adone.pop();
		}

		both.pop();
	}

	while(!both.empty() && !Adone.empty() && !Bdone.empty() && (Adone.top() + Bdone.top() > both.top())){
		com += both.top();
		Adone.pop();
		Bdone.pop();
		both.pop();
	}

	while(!both.empty() && !Adone.empty() && (Adone.top() > both.top())){
		com += both.top();
		Adone.pop();
		both.pop();
	}

	while(!both.empty() && !Bdone.empty() && (Bdone.top() > both.top())){
		com += both.top();
		Bdone.pop();
		both.pop();
	}

	while(!Adone.empty()){
		com += Adone.top();
		Adone.pop();
	}

	while(!Bdone.empty()){
		com += Bdone.top();
		Bdone.pop();
	}

	cout<<com;
}