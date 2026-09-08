class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int top=0;
        int bot=n-1;
        int left=0;
        int right=m-1;
        vector<int> ans;
        //right->down->left->up


       while(top<=bot && left<=right){
        //right
        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }

        //down
        for(int i=top+1;i<=bot;i++){
            ans.push_back(mat[i][right]);
        }

        //left
        // Check if there is a distinct bottom row remaining
        if(top<bot){
        for(int i=right-1;i>=left;i--){
            ans.push_back(mat[bot][i]);
        }
        }

        //up
        // Check if there is a distinct left column remaining
        if(left<right)
        for(int i=bot-1;i>top;i--){
            ans.push_back(mat[i][left]);
        }


        left++;
        right--;
        top++;
        bot--;
       }

       return ans;

    }
};
