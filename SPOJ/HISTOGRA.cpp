/*
case 1: If h[s.top()] is >= h[i];
	pop and check with h beging h[s.top()]

case 2: If s.empty() or h[s.top()] < h[i]
	push i to stack 
*/



class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0, n=h.size();
        stack<int> s;
        for(int i=0; i<n;){
        	if(!s.empty() && h[i] <= h[s.top()]){
        		int height = h[s.top()];
        		s.pop();

        		if(s.empty()){
        			ans = max(ans, height*i);
        		}
        		else{
        			ans = max(ans, height*(i-s.top()-1));
        		}
        	}
        	else{
        		s.push(i++);
        	}
        }
        while(!s.empty()){
        	int height = h[s.top()];
    		s.pop();

    		if(s.empty()){
    			ans = max(ans, height * n);
    		}
    		else{
    			ans = max(ans, height * (n - s.top()-1));
    		}
        }
        return ans;
    }
};