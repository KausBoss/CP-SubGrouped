/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define vi 			 vector<int>
#define pb           push_back
#define fi           first
#define si           second
#define pii 		 pair<int,int>
#define vii 		 vector<pair<int,int>>
#define F(a,n)       for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n)       for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n)      for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)      for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)     memset(a, b, sizeof a)
#define matrix(x) 	 vector<vector<x>>
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
priority_queue<ll> R, B, G;


bool checker(ll val, priority_queue<ll> *mn, priority_queue<ll> *rest1, priority_queue<ll> *rest2){
	if(mn->size() == 1){
		return 1;
	}
	if(rest1->top() < val && rest2->top() < val){
		return 1;
	}
	bool ret=1;
	if(rest1->top() == val){
		if(rest1->size() == 1){return 1;}
		rest1->pop();
		mn->pop();
		if(rest1->top() > mn->top()){ret  = 0;}
		rest1->push(val); mn->push(val);
		return ret;
	}
	if(rest2->top() == val){
		if(rest2->size() == 1){return 1;}
		rest2->pop();
		mn->pop();
		if(rest2->top() > mn->top()){ret  = 0;}
		rest2->push(val); mn->push(val);
		return ret;
	}
	return ret;
}

void func(){
	ll r, g, b;
	cin>>r>>g>>b;
	for(int i=0; i<r; i++){
		ll temp;cin>>temp;
		R.push(temp);
	}
	for(int i=0; i<g; i++){
		ll temp;cin>>temp;
		G.push(temp);
	}
	for(int i=0; i<b; i++){
		ll temp;cin>>temp;
		B.push(temp);
	}
	ll maxArea=0;
	while(!R.empty() && !B.empty() && !G.empty()){
		ll maxEdge = max(R.top(), max(B.top(), G.top()));

		if(maxEdge == R.top() && checker(maxEdge, &R, &G, &B)){
			R.pop();
			ll edge2 = max(G.top(), B.top());
			if(edge2 == G.top()){G.pop();}
			else{B.pop();}
			maxArea += maxEdge*edge2;
		}
		else if(maxEdge == G.top() && checker(maxEdge, &G, &R, &B)){
			G.pop();
			ll edge2 = max(R.top(), B.top());
			if(edge2 == R.top()){R.pop();}
			else{B.pop();}
			maxArea += maxEdge*edge2;
		}
		else if(checker(maxEdge, &B, &R, &G)){
			B.pop();
			ll edge2 = max(R.top(), G.top());
			if(edge2 == R.top()){R.pop();}
			else{G.pop();}
			maxArea += maxEdge*edge2;
		}
	}
	if(R.empty()){
		while(!G.empty() && !B.empty()){
			maxArea += G.top()*B.top();
			G.pop(); B.pop();
		}
	}
	if(G.empty()){
		while(!R.empty() && !B.empty()){
			maxArea += R.top()*B.top();
			R.pop(); B.pop();
		}
	}
	if(B.empty()){
		while(!R.empty() && !G.empty()){
			maxArea += R.top()*G.top();
			R.pop(); G.pop();
		}
	}
	cout<<maxArea<<endl;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;//cin>>t;
	while(t--){
		func();
	}
}