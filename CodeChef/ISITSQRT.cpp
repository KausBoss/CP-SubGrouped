/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           long 
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
const int nax = 1e5 + 200;
ll qual[nax], quan[nax];

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		ll n, q;
		cin>>n>>q;
		F(qual, n);
		F(quan, n);
		while(q--){
			int type;
			cin>>type;
			if(type==1){
				ll l, r, qt;
				cin>>l>>r>>qt;
				l--, r--;
				ll pt=qual[l];
				for(int i=l+1; i<=r; i++){
					if(qual[pt] < qual[i]){pt = i;}
				}
				quan[pt] += qt;
			}
			else{
				ll v, e, qt, thrs;
				cin>>v>>e>>qt>>thrs;
				e--;
				ll l = max(0l, e-v);
				ll r = min(n-1, e+v);
				ll pt=-1;
				for(int i=l; i<=r; i++){
					if(qual[i]>=thrs && (pt==-1 || (pt > -1 && qual[i] > qual[pt]))){
						pt = i;
					}
				}
				if(pt == -1){cout<<"No purchase\n";}
				else{
					cout<<pt+1<<"\n";
					quan[pt] -= qt;
				}
			}
		}
	}
}