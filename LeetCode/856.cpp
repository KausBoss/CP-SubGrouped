class Solution {
public:
    int scoreOfParentheses(string S) {
    	stack<int> s;
    	int ans=0, t1, t2;
    	for(auto x:S){
    		if(x == '('){
    			s.push(0);
    		}
    		else{
    			t1 = (s.top()) ? (s.top()) : 1;
    			s.pop();
    			if(s.empty()){ans += t1;}
    			else{
    				t2 = s.top();
    				s.pop();
    				s.push(t2 + 2*t1);
    			}
    		}
    	}
    	return ans;
     }
};