class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<int> s;
        int wrc=0;
        for(auto x:S){
        	if(x == '('){
        		s.push(0);
        	}
        	else {
        		if(s.empty()){
        			wrc++;
        		}
        		else{
        			s.pop();
        		}
        	}
        }
        return wrc + s.size();
    }
};