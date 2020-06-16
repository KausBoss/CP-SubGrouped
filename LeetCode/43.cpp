#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string multiply(string s1, string s2) {
    	vector<string> pos;
    	reverse(s1.begin(), s1.end());
    	reverse(s2.begin(), s2.end());
    	for(int i=0; i<s2.size(); i++){
    		string temp = s1;
    		int carry = 0;
    		for(int j=0; j<temp.size(); j++){
    			int curr = carry;
    			int n1 = s2[i] - '0';
    			int n2 = temp[j] - '0';
    			curr += n1 * n2;
    			temp[j] = (curr % 10) + '0';
    			carry = curr / 10;
    		}
    		while(carry){
    			temp.push_back((carry % 10) + '0');
    			carry /= 10;
    		}
    		reverse(temp.begin(), temp.end());
    		int j = i;
    		while(j--){temp.push_back('0');}
    		reverse(temp.begin(), temp.end());
    		cout<<temp<<endl;
    		pos.push_back(temp);
    	}
    	string ans= "";
    	int carry = 0;
    	for(int i=0; ; i++){
    		int sum = carry;
    		bool bag=false;
    		for(int j=0; j<pos.size(); j++){
    			if(i < pos[j].length()){
    				sum += pos[j][i] - '0';
    				bag = true;
    			}
    		}
    		if(!bag){break;}
    		cout<<i<<" "<<sum<<endl;
    		ans.push_back(((sum%10)+'0'));
    		carry = sum / 10;
    	}
    	while(carry){
			ans.push_back((carry % 10) + '0');
			carry /= 10;
    	}
    	cout<<ans<<endl;
    	while(ans[ans.length()-1] == '0' && ans.length() > 1){ ans.pop_back();}
    	reverse(ans.begin(), ans.end());
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}