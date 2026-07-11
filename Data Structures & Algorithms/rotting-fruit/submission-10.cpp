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
    int bfs(queue<temp> &q, vector<vector<int>> &grid, int fresh){
       int time=0;
       int n= grid.size();//rows
       int m= grid[0].size();//cols
       while(!q.empty()){
       
        int i=q.front().i;
        int j=q.front().j;
        time = q.front().time;
        q.pop();
       
        //checking fresh fruit all 4 sides
        if( i>0  && grid[i-1][j]==1){ //up
            grid[i-1][j]=2;
            fresh--;
            q.push(temp(i-1,j,time+1));
        }
        if( i<n-1 && grid[i+1][j]==1){ //down
            grid[i+1][j]=2;
            fresh--;
            q.push(temp(i+1,j,time+1));
        }
        if( j>0  && grid[i][j-1]==1){ //left
            grid[i][j-1]=2;
            fresh--;
            q.push(temp(i,j-1,time+1));
        }
        if( j<m-1  && grid[i][j+1]==1){ //right
            grid[i][j+1]=2;
            fresh--;
            q.push(temp(i,j+1,time+1));
        }
       
       }
        
       return fresh==0? time :-1;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();//rows
        int m= grid[0].size();//cols
        queue<temp> q; //i,j,time
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(temp(i,j,0));  
                }
                if(grid[i][j]==1){
                    fresh++;  
                }
            }
        }
        //bfs will start from multiple sources at once
        int mintime = bfs(q, grid, fresh);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==1){
        //             return -1;
        //         }
        //     }
        // }

        return mintime;
    }
};