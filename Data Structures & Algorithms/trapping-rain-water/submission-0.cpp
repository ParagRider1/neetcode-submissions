class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);

        
        leftmax[0]=heights[0];
        for(int i=1;i<n;i++){
           leftmax[i]=max(leftmax[i-1],heights[i-1]);
        }

        rightmax[n-1]=heights[n-1];
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],heights[i+1]);
        }
        
        int watertrapped=0;
        for(int i=0;i<n;i++){ //width=1;
            int currwatertrapped=min(leftmax[i],rightmax[i])-heights[i]; //in that particular ith bar
            if(currwatertrapped>0){
                watertrapped+=currwatertrapped;
            }
        }

        return watertrapped;

    }
};
