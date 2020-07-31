class Solution {
public:
    bool canJump(vector<int>& A) {
    	priority_queue<int> p;//<reach, index>
        p.push(A[0]);
        int n=A.size(), i=1, reach=A[0];
        while(!p.empty() && reach<n-1){
        	while(i<n && i<=reach){
        		p.push(A[i]+i);
        		i++;
        	}
        	reach = p.top();
        	p.pop();
        }
        return reach >= n-1;
    }
};