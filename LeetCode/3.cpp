#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[127];
        for(int i=0; i<127; i++){
        	freq[i] = -1;
        }
        int maxLen = 0, curlen = 0;
        int clear = 0;
        for(int i=0; i<s.length(); i++){
        	if(freq[s[i]] != -1){
        		maxLen = max(maxLen, curlen);
        		int j = clear;
        		clear = freq[s[i]] + 1;
	        	for(j = j; j <= freq[s[i]]; j++){
	        		cout<<"clearing: "<<j<<"\n";
	        		freq[s[j]] = -1;
	        		curlen--;
	        	}
        	}
        	curlen++;
            freq[s[i]] = i;
            cout<<s[i]<<" "<<maxLen<<" "<<curlen<<" "<<i<<endl;
        }
        maxLen = max(curlen, maxLen);
        return maxLen;
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

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 #endif
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}