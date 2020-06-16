class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        bitset<10001> freq;
        for(auto x:A){
            if(freq[x] != 0){ return x;}
            freq[x] = 1;
        }
        return 0;
    }
};