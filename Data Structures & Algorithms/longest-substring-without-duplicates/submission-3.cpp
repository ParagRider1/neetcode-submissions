class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1){
           return n;
        }
        //sliding window
        unordered_map<char,int> freq;
        int st=0;
        int end=1;
        freq[s[0]]++; //first letter adding
        int maxlen=0;
        int currlen=1;
        while(end<n){
           if(freq[s[end]]>0){
             while(freq[s[end]]>0){
                freq[s[st]]--;
                st++;
                currlen--;
                
             }
           }
           freq[s[end]]++;
           end++;
           currlen++;
           maxlen=max(currlen,maxlen);
   
        }

        return maxlen;




        // //Brute force


        // int n=s.size();
        // int maxlen=0;
        // for(int i=0;i<n;i++){
        //     unordered_map<char,int> freq;
        //     int len=0;
        //     for(int j=i;j<n;j++){
        //          if(freq.count(s[j])){
        //             break;
        //          }
        //        freq[s[j]]++;
        //        len++;
        //        maxlen=max(maxlen,len);
        //     }

        // } 

        // return maxlen;
    }
};
