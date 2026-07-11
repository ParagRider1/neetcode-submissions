class Solution {
public:
    
    void dfs(int i,int j, vector<vector<int>> &vis, vector<vector<char>>& grid){
        int n= grid.size();//rows
        int m= grid[0].size(); //col
        if(i<0 || i>=n || j<0 || j>=m){
           return;
        }
        if(vis[i][j]==1){
            return;
        }

        vis[i][j]=1;
        if(grid[i][j]=='1'){
       
        //left
        dfs(i,j-1,vis,grid);

        //right
         dfs(i,j+1,vis,grid);

        //up
        dfs(i-1,j,vis,grid);

        //down
        dfs(i+1,j,vis,grid);

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();//rows
        int m= grid[0].size(); //col
        //nXm
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){//row
            for(int j=0;j<m;j++){//col
                if( !vis[i][j]  && grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    count++;
                }else if(!vis[i][j]){
                    //=="0"
                    vis[i][j]=1;
                }
            }
        }
        return count;
    }
};
