class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //fixed length sliding window of size s1
        if(s2.size()<s1.size()){
            return false;
        }
        int l=s1.size();
        unordered_map<char,int> s1freq;
        for(int i=0;i<s1.size();i++){
            s1freq[s1[i]]++;

        }
        unordered_map<char,int> s2freq;

        int st=0;
        int end=l-1;
        for(int i=st;i<=end;i++){
            s2freq[s2[i]]++;
        }
        if(s2freq==s1freq){
            return true;
        }
        
        s2freq[s2[st]]--;
        if(s2freq[s2[st]]==0){
            s2freq.erase(s2[st]);
        }
        st++;
        end++;
        while(end<s2.size()){
            s2freq[s2[end]]++;
            if(s2freq==s1freq){
                return true;
            }
           
           s2freq[s2[st]]--;
           if(s2freq[s2[st]]==0){
            s2freq.erase(s2[st]);
           }
           st++;
           end++; 
        }
      
       for(auto e: s1freq){
        cout<<e.first<<": "<<e.second<<endl;
       }
       cout<<endl;
       for(auto e: s2freq){
        cout<<e.first<<": "<<e.second<<endl;
       }


       return false;


       
    }
};
