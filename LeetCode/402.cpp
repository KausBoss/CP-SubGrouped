class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(auto x:num){
    		while(!s.empty() && k>0 && x<s.top()){
    			s.pop();k--;
    		}
        	s.push(x);
        }
        if(s.empty()){return "0";}
        while(!s.empty() && k>0){
			s.pop();k--;
		}
        string ans="";
        while(!s.empty()){
        	ans += s.top();
        	s.pop();
        }
        while(!ans.empty() && ans.back() == '0'){ans.pop_back();}
        if(ans.empty()){return "0";}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};