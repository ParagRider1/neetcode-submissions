class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int st=0;
        int end=n-1;
        int maxarea=0;
        while(st<end){
            int width = end-st;
            int minheight=min(heights[st],heights[end]);
            int height=minheight;
            int area=width*height;
            maxarea=max(maxarea,area);
            if(minheight==heights[st]){
                st++;
            }else{
                end--;
            }

        }
        return maxarea;


    }
};
