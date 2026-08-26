class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n=strs.size();
        
       vector<string> orig=strs;
      // sorting each strings inside strs 
       for(int i=0;i<n;i++){ //n*mlogm  
          sort(strs[i].begin(),strs[i].end());
       }
    
  
       vector<vector<string>> ans;
       vector<int> vis(n,0); //no need to erase , just keep vis array
       for(int i=0;i<n;i++){//main str to check (i) // n*n*m
            if(vis[i]==1){
             continue;
            }
            vector<string> anagrams;    
            anagrams.push_back(orig[i]);
            vis[i]=1;
            for(int j=i+1;j<n;j++){//to check (j) 
                    if(vis[j]==1){
                    continue;
                    }
                    if(strs[i].size()!=strs[j].size()){
                        continue;
                    }
                    bool same=true;
                    for(int len=0;len<strs[i].size();len++){
                        if(strs[i][len]!=strs[j][len]){
                            same=false;
                            break;
                        }
                    }
                    if(same==true){
                        anagrams.push_back(orig[j]);
                        vis[j]=1;
                        j--;
                    }

            }
            
            ans.push_back(anagrams);

       }
       return ans;

    }
};
