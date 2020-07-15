class Solution {
	#define mod 1000000007
public:
    int sumSubarrayMins(vector<int>& A) {
        int n= A.size();
        vector<int> right(n), left(n);
        stack<int> s;
        for(int i=0; i<n; i++){
        	while(!s.empty() && A[s.top()] > A[i]){
        		right[s.top()] = i - s.top();
        		s.pop();
        	}
        	s.push(i);
        }
        while(!s.empty()){
        	right[s.top()] = n-s.top();
        	s.pop();
        }
        for(int i=n-1; i>=0; i--){
        	while(!s.empty() && A[s.top()] >= A[i]){
        		left[s.top()] = s.top() - i;
        		s.pop();
        	}
        	s.push(i);
        }
        while(!s.empty()){
        	left[s.top()] = s.top() + 1;
        	s.pop();
        }
        int ans =0;
        for(int i=0; i<n; i++){
            ans += ((left[i]%mod)*(right[i]%mod)*(A[i]%mod))%mod;
            ans %=mod;
        }
        return ans;
    }
};