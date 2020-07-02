/*
first append an empty char before both strings text as well as pattern
make a boolean dp matrix with all values as false
make dp[0][0]=1 because empty string of text will match with empty string of pattern
new we will edit the dp[0][~] row because strings like a* can matc with empty text
now we will iterate over matrix
if(char[s] == char[p] || char[p] == '.') make dp[i][j]=1
if(char[p] == '*'){
	we will have 2 case
	case 1. dp[i][j] = d[i][j-2] //this is the case when char preceding the * has occurance == 0
	case 2. if(char[s] == char preceding * || char preceding * == .){
	dp[i][j] |= dp[i-1][j]
	}
}

*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        s = ' ' + s;
        p = ' ' + p;
        int n=s.size(), m=p.size();
        vector<vector<bool>> dp(n, vector<bool>(m, 0));
        dp[0][0]=1;
        for(int i=2; i<m; i++){
        	if(p[i] == '*'){dp[0][i]=dp[0][i-2];}
        }

        for(int i=1; i<n; i++){
        	for(int j=1; j<m; j++){
        		if(s[i] == p[j] || p[j] == '.'){
        			dp[i][j] = dp[i-1][j-1];
        		}
        		else if(p[j] == '*'){
        			dp[i][j] = dp[i][j-2];
        			if(s[i] == p[j-1] || p[j-1] == '.'){
        				dp[i][j] = dp[i][j] || dp[i-1][j];
        			}
        		}
        	}
        }
        return dp[n-1][m-1];
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}