class Solution {
public:
    // void calcIndegree(vector<vector<int>> adj,vector<int> &indeg){
    //     int n=adj.size();//numCourses
    //     for(int i=0;i<n;i++){
    //         for(int v: adj[i]){
    //              indeg[v]++;
    //         }
    //     }

    // }
    bool isDirectedCycle(int u,vector<int> &recPath,vector<int> &vis,vector<vector<int>> &adj){
          vis[u]=1;
          recPath[u]=1;

          for(int v: adj[u]){
            if(!vis[v]){
                if(isDirectedCycle(v,recPath,vis,adj)){
                    return true;
                }
            }else{ //vis already 
                    if(recPath[v]==1){
                        return true;//cycle exist
                    }
            }
          }
          
          recPath[u]=0;
          return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prereq.size();i++){//directed graph
            //[a,b] // b->a
            adj[prereq[i][1]].push_back(prereq[i][0]);

        }
        //just check toposort exists
        //basically check directed cycle detection code
        vector<int> vis(numCourses,0);
        vector<int> recPath(numCourses,0);
        //for directed graph have to check for all vertices
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
             if(isDirectedCycle(i,recPath,vis,adj)){
                 return false;//means cycle exist and cantfinish
             }
            }
        }

        return true;


        // vector<int> indeg(numCourses);
        // calcIndegree(adj,indeg);
        // queue<int> q;
        // for(int i=0;i<indeg.size();i++){
        //     if(indeg[i]==0){
        //         q.push(i);//vertex with 0 indeg //starting pt
        //     }
        // }
        // if(q.empty()){//no starting pt//cycle exist //no 0 indeg vertex
        //    return false;
        // }

        // while(!q.empty()){//basically cycle detection and not topo sort even bcz we dont need to print order
        //                   //toposort exist in directed acyclic graph, so basically cycle detection code
             
        // }



    }
};
