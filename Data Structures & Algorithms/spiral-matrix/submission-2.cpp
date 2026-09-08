class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        if (mat.empty()) return ans;
        
        int top = 0, bot = mat.size() - 1;
        int left = 0, right = mat[0].size() - 1;
        
        while (top <= bot && left <= right) {
            // Traverse Right
            for (int i = left; i <= right; i++) {
                ans.push_back(mat[top][i]);
            }
            top++; // Shrink top boundary immediately
            
            // Traverse Down
            for (int i = top; i <= bot; i++) {
                ans.push_back(mat[i][right]);
            }
            right--; // Shrink right boundary immediately
            
            // Check if a bottom row still exists
            if (top <= bot) {
                // Traverse Left
                for (int i = right; i >= left; i--) {
                    ans.push_back(mat[bot][i]);
                }
                bot--; // Shrink bottom boundary immediately
            }
            
            // Check if a left column still exists
            if (left <= right) {
                // Traverse Up
                for (int i = bot; i >= top; i--) {
                    ans.push_back(mat[i][left]);
                }
                left++; // Shrink left boundary immediately
            }
        }
        
        return ans;
    }
};