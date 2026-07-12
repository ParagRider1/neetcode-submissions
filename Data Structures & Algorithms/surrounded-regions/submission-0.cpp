class Solution {
public:
    
    void dfs(int i, int j,vector<vector<int>> &vis,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        if(i<0||j<0||i>=n||j>=m){
            return;
        }
        if(vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        if(board[i][j]=='O'){
            dfs(i-1,j,vis,board);
            dfs(i+1,j,vis,board);
            dfs(i,j-1,vis,board);
            dfs(i,j+1,vis,board);
        }
       
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(board[i][j]=='O' && (i==0 || j==0 || i==n-1|| j==m-1)){
                        dfs(i,j,vis,board);
                        
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){ 
                   board[i][j]='X';
                }
            }
        }
        
       
    }
};
