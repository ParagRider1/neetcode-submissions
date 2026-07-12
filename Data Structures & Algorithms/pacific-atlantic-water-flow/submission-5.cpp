class Solution {
public:
    //many things learned// can pass bool or int &variable direct and save permanently
    bool dfs(int i, int j,bool &pacific, bool &atlantic,vector<vector<int>>& vis,vector<vector<int>>& heights){
        int n=heights.size();
        int m=heights[0].size();
         if(i<=0 || j<=0 ){
            pacific=true;
         }
         if(i>=n-1 || j>=m-1){
            atlantic=true;
         }
         if(atlantic && pacific){//main condition
            return true;
         }
          
         vis[i][j]=1;
        //up
        if(i>0 && heights[i-1][j]<=heights[i][j] && !vis[i-1][j]){
             if(dfs(i-1,j,pacific,atlantic,vis,heights)){
                return true;
             }
         }

         //down
         if(i<n-1 && heights[i+1][j]<=heights[i][j] && !vis[i+1][j]){
             if(dfs(i+1,j,pacific,atlantic,vis,heights)){
                return true;
             }
         }
         //left
         if(j>0 && heights[i][j-1]<=heights[i][j] && !vis[i][j-1]){
             if(dfs(i,j-1,pacific,atlantic,vis,heights)){
                return true;
             }
         }
         //right
         if(j<m-1 && heights[i][j+1]<=heights[i][j] && !vis[i][j+1]){
             if(dfs(i,j+1,pacific,atlantic,vis,heights)){
                return true;
             }
         }

        
        return false;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));

//and need vis bcz for same height , it just loop up down up down
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool atlantic=false;
                bool pacific=false;
                 //vector<vector<int>> vis(n,vector<int>(m,0)); //due to this MLE error coming 
                bool flow=dfs(i,j,pacific,atlantic,vis,heights);
                if(flow){
                    ans.push_back({i,j});
                }

                //clear vis efficiently and fix Memory limit error
                for(int i=0;i<n;i++){//row
                    fill(vis[i].begin(),vis[i].end(),0);
                }

            }
        }

        return ans;
    }
};
