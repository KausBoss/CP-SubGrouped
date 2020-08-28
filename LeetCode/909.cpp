class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int grid = n * n;

        //map numbers to places (makes traversal easier)
        int flag = 0, pos = 1;
        map <int, pair <int,int>> mp;
        for(int i = n - 1; i >= 0; i--) {
            if(flag == 0) {
                for(int j = 0; j < n; j++) {
                    mp[pos] = {i, j};
                    pos++;
                }
                flag = 1;
            } else {
                for(int j = n - 1; j >= 0; j--) {
                    mp[pos] = {i, j};
                    pos++;
                }
                flag = 0;
            }
        }

        //build  the graph
        vector <int> adj[grid + 1];
        for(int i = 1; i <= grid; i++) {
            for(int j = i + 1; j <= i + 6; j++) {
                if(j <= grid) {
                    //retrieve the positions
                    int row = mp[j].first, col = mp[j].second;
                    if(board[row][col]  == -1) {
                        adj[i].push_back(j);
                    } else {
                        adj[i].push_back(board[row][col]);
                    }

                }
            }
        }


        //do BFS and keep storing distances
        //initially all nodes at diatance infinity
        vector <int> dist(grid + 1, INT_MAX);
        queue <int> Q;

        Q.push(1);
        dist[1] = 0;

        while(!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            for(int next : adj[curr]) {
                if(dist[next] == INT_MAX) {
                    Q.push(next);
                    //distance of parent + 1
                    dist[next] = dist[curr] + 1;
                    if(next == grid) break;
                }
            }
        }
 

        //return ans
        //if dist if infinity then destination is not reachable
        return dist[grid] == INT_MAX ? -1 : dist[grid];
    }
};