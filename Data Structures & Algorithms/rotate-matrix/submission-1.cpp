class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
       
        //rotating 90* inplace == transpose(by swapping i,j with j,i in LTM) + reversing each rows
        //for rotating 180* inplace = apply above for x2 times 
        int n=mat.size();//rows
        int m=mat[0].size();//col


        //transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }

        //reversing each row
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }

    }
};
