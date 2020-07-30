class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> t(N+1, 0);
        vector<set<int>> here(N+1);
        for(auto x: trust){
        	t[x[0]]++;
        	here[x[1]].insert(x[0]);
        }
        for(int i=1; i<=N; i++){
        	if(here[i].size() == N-1 && t[i]==0){
        		return i;
        	}
        }
        return -1;
    }
};