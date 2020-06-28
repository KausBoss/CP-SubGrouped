/*

*/
#include <iostream>
#include <map>

using namespace std;

#define ll long long int

int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;cin>>t;
	while(t--){
		ll n, k, temp, mx=0;
		cin>>n>>k;
		map<ll,ll> m;
		for(ll i=0; i<n; i++){
			cin>>temp;
			ll val = k - (temp%k);
			if(val != k){
				if(m.count(val) == 0){
					m[val]= 1;
				}
				else{
					m[val]++;
				}
				if(m[mx] < m[val] ||(m[mx] == m[val] && val > mx)){
					mx = val;
				}
			}
		}
		ll ans = m.count(mx) ? (k*(m[mx] - 1) + mx +1) : 0;
		cout<<ans<<"\n";
		m.clear();
	}
}