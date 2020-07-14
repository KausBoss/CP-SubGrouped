class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0){return 0;}
        int m = matrix[0].size();
        stack<int> s;
        int height, ans=0;
        vector<int> h(m, 0);
        for(int i=0; i<n; i++){
        	int j;
        	for(j=0; j<m;){
        		int k=i;
        		h[j]=0;
        		while(k>=0 && matrix[k][j]=='1'){h[j]++;k--;}
                // cout<<h[j]<< " "<<i<<endl;
        		if(!s.empty() && h[j] <= h[s.top()]){
        			height = h[s.top()];
        			s.pop();
        			if(s.empty()){
        				ans = max(ans, height*j);
        			}
        			else{
        				ans = max(ans, height*(j - s.top() - 1));
        			}
        		}
        		else{
        			s.push(j++);
        		}
        	}
        	while(!s.empty()){
        		height = h[s.top()];
        		s.pop();
        		if(s.empty()){
    				ans = max(ans, height*j);
    			}
    			else{
    				ans = max(ans, height*(j - s.top() - 1));
    			}
        	}
        }
        return ans;
    }
};