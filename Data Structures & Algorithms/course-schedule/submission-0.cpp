class Solution {
public:

    bool iscycledir(int src,vector<bool> &vis,vector<bool> &rec,vector<vector<int>> &adj){
        vis[src]=true;
        rec[src]=true;

        for(int v:adj[src]){
            if(!vis[v]){
                if(iscycledir(v,vis,rec,adj)){
                    return true;
                }
            }else{

                if(rec[v]){
                    return true;
                }
            }
        }

        rec[src]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //is there exist topological order
        //must be DAG for topo

        //cycle detection dir  - if cycle exist- false, and no cycle - true topo exist
         int V = numCourses;
         vector<vector<int>> adj(V);
         for(int i=0;i<prerequisites.size();i++){
           int u=prerequisites[i][1];
           int v=prerequisites[i][0];
           adj[u].push_back(v);
         }


         vector<bool> vis(V,false);
         vector<bool> rec(V,false);  //recpath current one

         for(int i=0;i<V;i++){
            if(!vis[i]){
            if(iscycledir(i,vis,rec,adj)){
                return false;  //not dag
            }
            }
         }

         return true;
    }
};