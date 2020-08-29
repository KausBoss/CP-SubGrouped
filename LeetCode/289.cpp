class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(), m=board[0].size();
        int mx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
        int my[8]={0, 1, 1, 1, 0, -1, -1, -1};

        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		int nbhr = 0;
        		for(int k=0; k<8; k++){
                    if(i+mx[k]>=n || i+mx[k]<0 || j+my[k]>=m || j+my[k]<0){continue;}
        			if(board[i+mx[k]][j+my[k]]==1 || board[i+mx[k]][j+my[k]]==-1){nbhr++;}
        		}
        		if((nbhr<2 || nbhr>3) && (board[i][j]==1)){board[i][j]=-1;}
        		else if(nbhr==3 && board[i][j]==0){board[i][j]=2;}
        	}
        }
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(board[i][j]==-1){board[i][j]=0;}
        		else if(board[i][j]==2){board[i][j]=1;}
        	}
        }
    }
};