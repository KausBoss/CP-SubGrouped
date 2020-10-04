/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll           		long long int
#define vi 				 	vector<int>
#define pb      	     	push_back
#define fi          	 	first
#define si      	     	second
#define pii		 		 	pair<int,int>
#define vii 			 	vector<pair<int,int>>
#define F(a,n)  	     	for(int i=0;i<n;i++){cin>>a[i];}
#define P(a,n) 		    	for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define fastIO      	 	ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F1(a,n) 	     	for(int i=1;i<=n;i++){cin>>a[i];}
#define P1(a,n)     		for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define mem(a,b)	     	memset(a, b, sizeof a)
#define matrix(x) 		 	vector<vector<x>>
#define NF(a,n,m)      	    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)		    for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  	 	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  		for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define ceil_div(x, y) 		(((x) + (y) - 1) / (y))
const int nax = 1e7;
const int mod = 1e9+7;

struct job{
	int id, deadline, profit;
};

bool sorter(job a, job b){
	if(a.profit == b.profit){
		return a.deadline < b.deadline;
	}
	return a.profit > b.profit;
}

void func(){
	int n, maxline=0;
	cin>>n;
	job allJobs[n];
	for(int i=0; i<n; i++){
		cin>>allJobs[i].id>>allJobs[i].deadline>>allJobs[i].profit;
		maxline = max(maxline, allJobs[i].deadline);
	}
	sort(allJobs, allJobs + n, sorter);
	vector<int> prof(maxline, 0);
	for(int i=0; i<n; i++){
		if(prof[allJobs[i].deadline-1] == 0){
			prof[allJobs[i].deadline-1] = allJobs[i].profit;
			// cout<<"Placed "<<allJobs[i].id<<" at *"<<allJobs[i].deadline-1<<endl;
		}
		else{
			int j = allJobs[i].deadline-1;
			while(j >= 0){
				if(prof[j] == 0){
					// cout<<"Placed "<<allJobs[i].id<<" at "<<j<<endl;
					prof[j] = allJobs[i].profit;
					break;
				}
				j--;
			}
		}
	}
	int done=0, ans=0;
	for(int i=0; i<maxline; i++){
		if(prof[i]){
			done++;
			ans += prof[i];
		}
	}
	// P(prof, n);
	cout<<done<<" "<<ans<<endl;
}

int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		func();
	}
}