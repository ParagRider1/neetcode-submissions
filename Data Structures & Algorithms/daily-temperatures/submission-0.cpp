class Solution {
public:

//using stack
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> s;

        for(int i=n-1;i>=0;i--){
            while(!s.empty()){
                if(s.top().first>temp[i]){
                    ans[i]=s.top().second-i;
                    break;
                }else{
                    s.pop();
                }
            }
            s.push({temp[i],i});
        }

        return ans;

    }   

};
