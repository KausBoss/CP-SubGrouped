#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
    	vector<int> perf;
    	for(int i=1; i*i<=n; i++){
    		perf.push_back(i*i);
    	}
    	vector<int> dp(n+1, INT_MAX);
    	dp[0] = 0;
    	dp[1] = 1;
    	for(int i=2; i<=n; i++){
    		for(int j=0; j<perf.size() && perf[j] <= i; j++){
    			dp[i] = min(dp[i], 1 + dp[i - perf[j]]);
    		}
    	}
    	return dp[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().numSquares(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
