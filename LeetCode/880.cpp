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
    string decodeAtIndex(string S, int k) {
        stack<pair<string, long long int>> s;
        string a="";
        for(auto x:S){
            if(isdigit(x)){
                s.push({a, (a.length()+(s.empty() ? 0 : s.top().second))*(x-'0')});
                a="";
            }
            else{
                a.push_back(x);
            }
            if(!s.empty() && s.top().second >= k){
                break;
            }
        }
        if(!a.empty()){
            s.push({a, (a.length()+(s.empty() ? 0 : s.top().second))});
        }
        while(!s.empty()){
            auto p = s.top();
            string x= p.first;
            long long int l = p.second;
            s.pop();

            k %= (x.length() + (s.empty() ? 0 : s.top().second));
            if(k == 0){
                k = x.length() + ((s.empty() ? 0 : s.top().second));
            }
            if(s.empty()){
                string ans="";
                ans += x[k-1];
                return ans;
            }
            if(k>s.top().second){
                string ans = "";
                ans += x[k-s.top().second -1];
                return ans;
            }
        }
        return "";
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

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
        string S = stringToString(line);
        getline(cin, line);
        int K = stringToInteger(line);
        
        string ret = Solution().decodeAtIndex(S, K);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}