class Solution {
public:
//min minutes to make all fruits rotten
    //time count return in bfs maybe
    class temp{
     public:
        int i;
        int j;
        int time;

        temp(int i, int j, int time){
            this->i = i;
            this->j= j;
            this->time = time; 
        }

    };
    int bfs(queue<temp> &q, vector<vector<int>> &vis, vector<vector<int>> &grid){
       int time=0;
       int n= grid.size();//rows
       int m= grid[0].size();//cols
       while(!q.empty()){
       
        int i=q.front().i;
        int j=q.front().j;
        time = q.front().time;
        q.pop();

        if( i>0 && !vis[i-1][j] && grid[i-1][j]==1){ //up
            vis[i-1][j]=1;
            q.push(temp(i-1,j,time+1));
        }
        if( i<n-1 && !vis[i+1][j] && grid[i+1][j]==1){ //down
            vis[i+1][j]=1;
            q.push(temp(i+1,j,time+1));
        }
        if( j>0 && !vis[i][j-1] && grid[i][j-1]==1){ //left
            vis[i][j-1]=1;
            q.push(temp(i,j-1,time+1));
        }
        if( j<m-1 && !vis[i][j+1] && grid[i][j+1]==1){ //right
            vis[i][j+1]=1;
            q.push(temp(i,j+1,time+1));
        }
       
       }

       return time;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();//rows
        int m= grid[0].size();//cols
        queue<temp> q; //i,j,time
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push(temp(i,j,0));
                }
            }
        }

        int mintime = bfs(q, vis, grid);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return mintime;
    }
};