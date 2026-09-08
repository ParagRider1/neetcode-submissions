class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        //sliding window
        int i=0;
        m[s[i]]++;
        pair<char,int> maxfreq; //char,count
        maxfreq={s[i],1};
        int j=1;
        int maxlen=1;
        int len=1;

        while(j<s.size() && i<=j){
            m[s[j]]++;
            len++;
            if(maxfreq.first==s[j]){
                maxfreq.second++;
            }

            for(auto e:m){
                        if(e.second>maxfreq.second){
                            maxfreq={e.first,e.second};
                            break;
                        }
            }

           if( len-maxfreq.second<=k){
             maxlen=max(maxlen,len);
           }else if( len-maxfreq.second>k){
                while(len-maxfreq.second>k && i<s.size()){
                    m[s[i]]--;
                    if(maxfreq.first==s[i]){
                        maxfreq.second--;
                    }
                    i++;
                    len--;
                    //check now which is maxfreq char if changed so update
                    for(auto e:m){
                        if(e.second>maxfreq.second){
                            maxfreq={e.first,e.second};
                            break;
                        }
                    }
                }

           }
           
            maxlen=max(maxlen,len);
            j++;
        }
        return maxlen;
    }
};
