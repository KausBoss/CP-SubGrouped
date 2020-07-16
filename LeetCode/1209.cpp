class Solution {
public:
    string removeDuplicates(string S, int k) {
        stack<pair<char,int>> s;
        int same=1;
        for(auto x:S){
        	if(s.empty()){
        		s.push({x,1});
        	}
        	else {
        		if(x == s.top()){
        			s.push({x, s.top().second + 1});
        		}
        		else{
        			s.push({x, 1});
        		}
        		if(s.top().second == k){
        			int t=k;
        			while(t--){
        				s.pop();
        			}
        		}
        	}
        }
        string ans="";
        while(!s.empty()){
        	ans += s.top().first;
        	s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};