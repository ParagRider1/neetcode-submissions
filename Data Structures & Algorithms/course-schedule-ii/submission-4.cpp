class Solution {
public:
    bool isDirectedCycle(int u,vector<int> &recPath, vector<int> &vis, vector<vector<int>> &adj){
        vis[u]=1;
        recPath[u]=1;

        for(int v: adj[u]){
            if(!vis[v]){
                if(isDirectedCycle(v,recPath,vis,adj)){
                    return true;
                }
            }else{//already vis
                
                if(recPath[v]==1){
                    return true; //cycle exist
                }

            }
        }
        recPath[u]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<int> ans;
        vector<int> vis(numCourses,0);
        vector<int> recPath(numCourses,0);
        vector<vector<int>> adj(numCourses);
        
        for(int i=0;i<prereq.size();i++){//[0,1]  1->0 
            adj[prereq[i][1]].push_back(prereq[i][0]);
        }

        for(int i=0;i<numCourses;i++){
          if(!vis[i]){
           if(isDirectedCycle(i,recPath,vis,adj)){
            return ans; //empty as cycle exist no topo order
          }
          }
        }
        //here means acyclic directed graph

        vector<int> indeg(numCourses,0);
        //calcIndegree
        for(int i=0;i<numCourses;i++){
            for(int v: adj[i]){
                indeg[v]++;
            }
        }
        queue<int> q;
        fill(vis.begin(),vis.end(),0); //reset vis to 0

        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){//starting pt indeg 0 vertices
               q.push(i);
               vis[i]=1;
               
            }
        }
        
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);//order pushing

            for(int v: adj[u]){
                if(!vis[v]){
                    //vis[v]=1;
                    indeg[v]--; //pop 0 indeg vertices and reduce indeg of its neighbors and push once anyones indeg becomes 0
                    if(indeg[v]==0){
                        q.push(v);
                        vis[v]=1;
                    }

                }
            }

        }
        return ans;
    }
};
