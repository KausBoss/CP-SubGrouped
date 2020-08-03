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
const int nax = 1e7 +4;
const int mod = 1e9+7;
ll a[nax], temp[nax], n;

ll merge(ll s, ll m, ll e){
	ll ret = 0;

	ll i=s, j=m+1;
	ll k=s;
	while((i<=m) && (j<=e)){
		if(a[i] <= a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
			ret += (m-i);
		}
	}
	while(i <=m){temp[k++] = a[i++];}
	while(j <= e){temp[k++] = a[j++];}
	for(int i=s; i<=e; i++){
		a[i]=temp[i];
	}
	return ret;
}

ll mergeSort(ll s, ll e){
	//base case
	if(s >= e){
		return 0;
	} 
	//recursive case
	ll mid = (s+e)/2;
	ll left =mergeSort(s, mid);
	ll right = mergeSort(mid+1, e);

	ll cur = merge(s, mid, e);
	cout<<s<<" "<<e<<" "<<right<<" "<<left<<endl;
	return (left + cur + right);
}

void func(){
	cin>>n;
	F(a, n);
	cout<<mergeSort(0, n-1)<<endl;
}

int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}