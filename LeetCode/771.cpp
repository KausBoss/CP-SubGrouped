class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> m;
        for(auto x:J){
        	m[x] = 1;
        }
        int ans =0;
        for(auto x:S){
        	ans += m.count(x);
        }
        return ans;
    }
};