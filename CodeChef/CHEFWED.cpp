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
#define NF(a,n,m)     for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;
ll n, k, a[1001];


ll Argue(ll ar[]){
	ll ans=0;
	for(int i=1; i<=100; i++){
		if(ar[i] > 1){
			ans += ar[i];
		}
	}
	return ans;
}

ll func(ll pos, ll end, ll freq[]){
	//base case
	if(pos >= n){
		return 0;
	}
	//recursive case
	ll curFreq[101] = {0}, maxProf=0, pt=-1, curProf=0;
	// for(int i=pos; i<end-1; i++){cout<<a[i]<<" ";}
	// cout<<endl;
	for(int i=pos; i<n-1; i++){
		if((freq[a[i]] > 1 && curFreq[a[i]]==0) || 
		   (freq[a[i]]-curFreq[a[i]]==2 && curFreq[a[i]]!=1)){
			curProf++;
		}
		if(freq[a[i]] == 2 && curFreq[a[i]]==0){curProf++;}


		if((freq[a[i]]-curFreq[a[i]]==1 && curFreq[a[i]]!=0)||
		   (freq[a[i]]-curFreq[a[i]] > 2 && curFreq[a[i]]==1)){
			curProf--;
		}
		if(freq[a[i]]-curFreq[a[i]]==1 && curFreq[a[i]]==1){
			curProf--;
		}

		// if(freq[a[i]] - ==  && curFreq[a[i]]==1){curProf--;}
		// if(freq[a[i]] == 1 && curFreq[a[i]]>=1){curProf--;}
		// cout<<curProf<<" ";
		curFreq[a[i]]++;

		//if(curProf>=maxProf && (curProf>k ||(curProf==k && pt==-1))){//|| (curProf >= k && k ==1))){
		// if(curProf>=maxProf && curProf>=k){
		if(((curProf >= maxProf) && (curProf>k)) ||
		   (curProf>=maxProf && curProf==k && (pt==-1||k==1))){
			maxProf = curProf;
			pt = i;
		}
	}
	// cout<<endl<<pt<<endl;
	if(pt == -1){
		// cout<<"returning "<<Argue(freq) + k<<endl;
		return Argue(freq) + k;
	}

	memset(curFreq, 0, sizeof curFreq);
	for(int i=pos; i<=pt; i++){
		freq[a[i]]--;
		curFreq[a[i]]++;
	}

	return func(pos, pt, curFreq) + func(pt+1, end, freq);
}


int main(){
	fastIO
	#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		F(a, n);
		ll freq[101]={0};
		if(k == 1){
			vector<vector<ll>> table(1001, vector<ll>(101, 0));
			ll ct=0, behes=0;
			for(ll i=0; i<n; i++){
				if(table[ct][a[i]]+1 > k){
					ct++;
				}
				else{
					if(table[ct][a[i]] == 1){
						behes += 2;
					}
					else if(table[ct][a[i]] > 1){
						behes++;
					}
				}
				table[ct][a[i]]++;
			}
			cout<<k*(ct+1)+behes<<endl;
			continue;
		}
		for(int i=0; i<n; i++){
			freq[a[i]]++;
		}
		cout<<func(0, n-1, freq)<<endl;
	}
}