class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int minProd = a[0];
        int maxProd = a[0];
        int ans = a[0];
        int op1, op2;
        for(int i=1; i<n; i++){
        	op1 = minProd*a[i];
        	op2 = maxProd*a[i];
        	minProd = min(a[i], min(op1, op2));
        	maxProd = max(a[i], max(op1, op2));
        	ans = max(ans, maxProd);
        }
        return ans;
    }
};