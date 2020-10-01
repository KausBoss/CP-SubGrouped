#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("../inp.txt","r",stdin);
    freopen("../out.txt","w",stdout);
    #endif
	int n;
	cin>>n;
	vector<int> steps(n), dp(n+1, 0);
	for(int i=0; i<n; i++){
		cin>>steps[i];
	}
	dp[0] = 1;
	for(int i=0; i<n; i++){
		int last = min(n, i + steps[i]);
		for(int j = last; j> i; j--){
			dp[j] += dp[i];
		}
	}
	cout<<dp[n];
}