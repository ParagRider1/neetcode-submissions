class Solution {
public:
    bool iscycleundir(int u,int par, vector<int> &vis, vector<vector<int>> &adj){
        vis[u]=1;

        for(int v:adj[u]){
            if(!vis[v]){
              if(iscycleundir(v,u,vis,adj)){
                return true;
              }
            }else{
                //already visited
                if(v!=par){
                    return true; //cycle exist
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //valid tree means doesnt have any cycle and connected
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){//undirected
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
       
        //cycle detection in undirected graph
        vector<int> vis(n,0);
        
        if(iscycleundir(0,-1,vis,adj)){ //if connected it will visit all
            return false; //cycle exist then not tree
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;  //disconnected so not tree
            }
        }
         
        
       return true;
    }
};
