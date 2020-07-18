/*

*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
    	string ret="", ans="";
    	int times=0;
    	int n=s.length();
    	for(int i=0; i<n; i++){
    		cout<<i<<" "<<times<<" "<<ret<<" "<<ans<<endl;
    		if(isdigit(s[i])){
    			if(ret.size()){
    				int pos=i;
    				while(s[pos] != ']'){pos++;}
    				ret += decodeString(s.substr(i, pos-i+1));
    				i=pos;
    			}
    			else{
					times = 10*times + (s[i]-'0');
    			}
    		}
    		else if(isalpha(s[i])){
    			ret += s[i];
    		}
    		else if(s[i] == ']'){
    			while(times--){
    				ans += ret;
    			}
    			times=0;
                ret="";
    		}
    	}
    	if(ret.size()){
    		ans += ret;
    	}
    	return ans;
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
        
        string ret = Solution().decodeString(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}