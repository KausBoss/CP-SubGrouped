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
#define NF(a,n,m)    for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m)   for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m)   for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m)  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
const int nax = 1e7;
const int mod = 1e9+7;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    	multiset<pair<int,int>> s;
    	priority_queue<pair<int,int>> p;
    	int n=Capital.size();
    	for(int i=0; i<n; i++){
    		s.insert({Capital[i], Profits[i]});
    	}
    	int ans=W;
        auto it = s.begin();
    	while(k--){
    		//p = priority_queue<pair<int,int>> ();
    		//for(auto it=s.begin(); (it!=s.end()) && ((it->first)<=W); it++){
            while((it!=s.end()) && ((it->first)<=W)){
                pair<int,int> temp = *it;
    			p.push({temp.second, (temp.first)});
                it++;
            }    
    			// pair<int,int> temp = *it;
    			// p.push({temp.second, (temp.first)});
    		//}
            if(p.empty()){return ans;}
    		ans += p.top().first;
            //cout<<p.top().first<<" "<<p.top().second<<endl;
    		W +=p.top().first ;//- p.top().second);
    		s.erase({p.top().second, p.top().first});
            p.pop();
    	}
    	return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

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
        int k = stringToInteger(line);
        getline(cin, line);
        int W = stringToInteger(line);
        getline(cin, line);
        vector<int> Profits = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> Capital = stringToIntegerVector(line);
        
        int ret = Solution().findMaximizedCapital(k, W, Profits, Capital);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}