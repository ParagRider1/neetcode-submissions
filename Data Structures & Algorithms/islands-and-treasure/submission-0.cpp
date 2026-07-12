class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==0){
                   q.push({i,j});  //like multisource bfs
               }

            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop(); //ahh missed this 
            //up
            if(i>0 && grid[i-1][j]!=-1){
                if(grid[i][j]+1<grid[i-1][j]){
                    grid[i-1][j]=grid[i][j]+1;
                    q.push({i-1,j});
                }
            }

            //down
            if(i<n-1 && grid[i+1][j]!=-1){
                if(grid[i][j]+1<grid[i+1][j]){
                    grid[i+1][j]=grid[i][j]+1;
                    q.push({i+1,j});
                }
            }

            //left
            if(j>0 && grid[i][j-1]!=-1){
                if(grid[i][j]+1<grid[i][j-1]){
                    grid[i][j-1]=grid[i][j]+1;
                    q.push({i,j-1});
                }
            }

            //right
            if(j<m-1 && grid[i][j+1]!=-1){
                if(grid[i][j]+1<grid[i][j+1]){
                    grid[i][j+1]=grid[i][j]+1;
                    q.push({i,j+1});
                }
            }
        }





    }
};
