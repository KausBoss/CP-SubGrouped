#include <bits/stdc++.h>

using namespace std;

#define ll long long
int steps=INT_MAX;

void func(int *ar, int i, int n, int st, bool visted[]){
	//base case
	if(i==n){
		steps = min(steps, st);
		return;
	}
	//recusrive case
	visted[i]=true;

	if(!visted[i+1]){
		func(ar, i+1, n, st+1, visted);
	}
	if(!visted[i+ar[i]] && (i+ar[i])>=0 && (i+ar[i])<=n){
		func(ar, i+ ar[i], n, st+1, visted);
	}
	visted[i]=false;
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int t, n, a[21];
	bool visted[21];
	cin>>t;
	while(t--){
		steps=INT_MAX;
		memset(visted, false, sizeof(visted));
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		func(a, 0, n, 0, visted);
		cout<<steps<<endl;
	}
}