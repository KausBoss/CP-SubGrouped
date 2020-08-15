class Solution {
public:
	class DSU{
		public:
		vector<int> parent;
		DSU(int n){
			parent.resize(n);
			for(int i=0; i<n; i++){
				parent[i] = i;
			}
		}
		int find(int x){
			if(parent[x] != x) 
			return parent[x] = find(parent[x]);
            return parent[x];
		}
		void unin(int x, int y){
			parent[find(x)] = find(y);
		}

	};
    int removeStones(vector<vector<int>>& s) {
        int n = s.size();
        DSU dsu(20000);

        for(auto x:s){
        	dsu.unin(x[0], x[1]+10000);
        }

        set<int> seen;
        for(auto x:s){
        	seen.insert(dsu.find(x[0]));
        }

        return n - seen.size();
    }
};