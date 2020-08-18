/*

*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main(){
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	vector<ll> v(1, 1);
	v.reserve((int)1e4 + 5);
	ll p2=0, p3=0, p5=0;
	while(v.size() < 10001){
		ll next = min(v[p2]*2, min(v[p3]*3, v[p5]*5));
		v.push_back(next);
		if(next == v[p2]*2){p2++;}
		if(next == v[p3]*3){p3++;}
		if(next == v[p5]*5){p5++;} 
	}
	ll t=1;cin>>t;
	while(t--){
		ll n;cin>>n;
		cout<<v[n-1]<<"\n";
	}
}