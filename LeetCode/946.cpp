class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j=0, n=popped.size();

        for(auto x:pushed){
        	s.push(x);
        	while(!s.empty() && j<n && popped[j] == s.top()){
        		s.pop();
        		j++;
        	}
        }
        return s.empty() && j==n;
    }
};