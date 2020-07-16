class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for(auto x:S){
        	if(s.empty()){
        		s.push(x);
        	}
        	else{
        		if(x == s.top()){
        			s.pop();
        		}
        		else{
        			s.push(x);
        		}
        	}
        }
        string ans="";
        while(!s.empty()){
        	ans += s.top();
        	s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};