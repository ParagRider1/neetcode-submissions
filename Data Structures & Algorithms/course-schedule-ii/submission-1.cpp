class Solution {
public:

     bool iscycledir(int src, vector<bool> &rec, vector<bool> &vis, vector<vector<int>> &adj){
         vis[src]=true;
         rec[src]=true;

         for(int v: adj[src]){
            if(!vis[v]){
                if(iscycledir(v,rec,vis,adj)){
                    return true;
                }
            }else{//visited

                if(rec[v]){
                    return true;
                }
            }
         }

         rec[src]=false;
         return false;
     }


     void toposort(int src, vector<bool> &vis,vector<vector<int>> &adj, stack<int> &s){
        vis[src]=true;

        for(int v: adj[src]){
            if(!vis[v]){
                toposort(v,vis,adj,s);
            }
        }

        s.push(src);
     }


   //directed
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //toposort q 
        int V=numCourses;
        //building first adj list 
        vector<vector<int>> adj(V);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);

        }
        
        
        vector<int> ans; //topo order
        //first cycle detection
        vector<bool> vis(V,false);
        vector<bool> rec(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(iscycledir(i,rec,vis,adj)){  //cycle in graph so no topo order possible
                    return ans; //empty
                }
            }
        }


        //no cycle

        //implement toposort-dfs

        vector<bool> vis2(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){  //bcz directed
            if(!vis2[i]){
               toposort(i,vis2,adj,s);
            }
        }
        
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
        

    }
};
