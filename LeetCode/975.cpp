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

class Solution {
public:
    int oddEvenJumps(vector<int> A) {
    	int n = A.size();
    	vector<bool> oddPoss(n, 0), evePoss(n, 0);
    	map<int, int> m;
    	oddPoss[n-1] = 1;
    	evePoss[n-1] = 1;
    	m[A[n-1]] = n-1;

    	for(int i=n-2; i>=0; i--){
    		auto itr1 = m.lower_bound(A[i]);
    		if(itr1 == m.end()){
    			oddPoss[i] = 0;
    		}
    		else{
    			oddPoss[i] = evePoss[itr1->second];
    		}

    		auto itr2 = m.upper_bound(A[i]);
    		if(itr2 == m.begin()){
    			evePoss[i] = 0;
    		}
    		else{
    			evePoss[i] = oddPoss[(--itr2)->second];
    		}
    		m[A[i]] = i;
    	}
    	int ans = 0;
    	for(auto x:oddPoss){
    		ans += x;
    	}
    	return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        
        int ret = Solution().oddEvenJumps(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}



