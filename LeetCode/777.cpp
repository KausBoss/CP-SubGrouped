#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
       int n = start.length();
       string s1 = "", s2 = "";
       for(auto x:start){
       		if(x != 'X'){s1.push_back(x);}
       }
       for(auto x:end){
       		if(x != 'X'){s2.push_back(x);}
       }
       if(s1 != s2){return 0;}
       int i, j;
       for(i = 0, j = 0; i < n && j < n;){
	       	if(start[i] == 'X'){
	       		i++;
	       	}
	       	else if(end[j] == 'X'){
	       		j++;
	       	}
	       	else{
	       		if((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)){
	       			return 0;
	       		}
	       		i++; 
	       		j++;
	       	}
       }
       return 1;
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
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    string line;
    while (getline(cin, line)) {
        string start = stringToString(line);
        getline(cin, line);
        string end = stringToString(line);
        
        bool ret = Solution().canTransform(start, end);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
