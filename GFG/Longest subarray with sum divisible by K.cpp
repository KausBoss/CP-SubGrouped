/*

*/
#include <bits/stdc++.h>

using namespace std;

#define ll          long long int
#define fastIO       ios_base::sync_with_stdio(false); cin.tie(NULL);
const int nax = 1e7;
const int mod = 1e9+7;
int main(){
	fastIO
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int t=1;cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		ll a[(int)1e6 + 5];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		map<int, int> m;
		m[0] = -1;
		int val = 0, maxSize = 0;
		for(int i=0; i<n; i++){
			val += a[i];
			val = (val + k)%k;
			if(m.find(val) != m.end()){
				maxSize = max(maxSize, i - m[val]);
			}
			else{
				m[val] = i;
			}
		}
		cout<<maxSize<<"\n";
	}
}