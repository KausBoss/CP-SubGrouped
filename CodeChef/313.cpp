class Solution {
public:
    int nthSuperUglyNumber(int k, vector<int>& primes) {
        int n=primes.size();
        vector<int> v(1,1);
        vector<int> pt(n, 0);
        while(v.size() <k){
        	int pb=INT_MAX;
        	for(int i=0; i<n; i++){
        		pb = min(pb, v[pt[i]]*primes[i]);
        	}
        	for(int i=0; i<n; i++){
        		if(pb == v[pt[i]]*primes[i]){
        			pt[i]++;
        		}
        	}
        	v.push_back(pb);
        }

        return v.back();
    }
};