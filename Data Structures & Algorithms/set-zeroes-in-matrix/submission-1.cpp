class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();

      vector<vector<bool>> skip(n,vector<bool>(m,false));
    
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(skip[i][j]==false){
                 if(mat[i][j]==0){
                    //setting row 0
                    for(int k=0;k<m;k++){
                        if(mat[i][k]==0){
                            continue;
                        }
                        mat[i][k]=0;
                        skip[i][k]=true;
                    }
                    //setting col 0
                    for(int k=0;k<n;k++){
                        if(mat[k][j]==0){
                           continue;
                        }
                        mat[k][j]=0;
                        skip[k][j]=true;
                    }
                 }
            }
        }
      }

    }
};
