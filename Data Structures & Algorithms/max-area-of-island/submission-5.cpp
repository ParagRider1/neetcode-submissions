class Solution {
public:
    int vertex=0;

    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n = grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return;
        }
        if(vis[i][j]==1){
            return;
        }

        vis[i][j]=1;
      
        if(grid[i][j]==1){
           vertex++;
         
        //up
        dfs(i-1,j,vis,grid);
        //down
        dfs(i+1,j,vis,grid);
        //left
        dfs(i,j-1,vis,grid);
        //right
        dfs(i,j+1,vis,grid); 
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                     vertex=0; //new island component
                    if(grid[i][j]==1){
                       dfs(i,j,vis,grid);
                       maxarea=max(vertex,maxarea);
                    }
                    vis[i][j]=1;
                }
            }
        }

        return maxarea;
    }
};
