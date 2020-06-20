#include <iostream>
#include <map>
#include <climits>

using namespace std;

int a[100], b[100], n, k;
map<pair<int,int>, int> m;

int func(int i, int sum){
	// base case
	if(i == n){
		//if sum is 0 that means we have a valid set of fruits
		//else we return INT_MIN to discard the option
		if(sum == 0){
			return 0;
		}
		return INT_MIN;
	}
	//recursive case
	if(m.count({i, sum})){ return m[{i, sum}];}

	//when item i is chosen
	int opt1 = a[i] + func(i+1, sum + a[i] - k*b[i]);
	//when item i is discarded
	int opt2 = func(i+1, sum);

	return m[{i, sum}] = max(opt1, opt2);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>n>>k;
    for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for (int i=0; i<n; i++){
		cin>>b[i];
	}

    int ans = func(0, 0);
    ans = (ans == 0) ? -1 : ans;
    cout<<ans;
}