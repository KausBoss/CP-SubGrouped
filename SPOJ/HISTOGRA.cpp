/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define mp          make_pair
#define pb          push_back
#define fi          first
#define si          second
#define fastIO      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n)      for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n)     for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n)      for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n)     for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;



int main(){
fastIO
#ifndef ONLINE_JUDGE
    freopen("../inp.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
	ll n;
	cin>>n;
	while(n){
		vector<ll> h(n);
		F(h, n);
		stack<ll> s;
		ll ans=0, i, height;
		for(i=0; i<n; ){
			if(!s.empty() && h[i] <= h[s.top()]){
				height = h[s.top()]; // height will be of the poping index
				s.pop();
				//if stack is empty that means all previous bars were taller
				// than the recently popped bar
				if(s.empty()){
					ans = max(ans, height*i);
				}
				//otherwise previous bars greater than the present bar
				//will be the ones which are in btw current index and s.top()
				else{
					ans = max(ans, height*(i - s.top() - 1));
				}
			}
			else{
				s.push(i++);
			}
			if(!s.empty())cout<<s.top()<<" "<<i<<" "<<ans<<endl;
			else{cout<<-1<<" "<<i<<" "<<ans<<endl;}
		}

		while(!s.empty()){
			height = h[s.top()];
			s.pop();
			if(s.empty()){
				ans = max(ans, height*i);
			}
			else{
				ans = max(ans, height*(i - s.top() - 1));
			}
		}
		cout<<ans<<endl;
		cin>>n;
	}
}