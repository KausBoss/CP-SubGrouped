class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans="";
        stack<int>s;
        for(auto x:S){
        	if(x == '('){
        		if(!s.empty()){ans += x;}
        		s.push(0);
        	}
        	else{
        		if(s.size() > 1){ans += x;}
        		s.pop();
        	}
        }
        return ans;
    }
};