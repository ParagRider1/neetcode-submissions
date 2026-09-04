class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.size()==0 || (s.size()<t.size())){
        return "";
        } 
        unordered_map<char,int> countt;

        for(int i=0;i<t.size();i++){
        countt[t[i]]++;
        }
        
        unordered_map<char,int> window;
        int have=0; //uniq char that satisfied count in window as countt 
        int need=countt.size();
        pair<int,int> res={-1,-1};
        int reslen=INT_MAX;

        int st=0;
        int end=0;

        for(end=0;end<s.size();end++){
            window[s[end]]++;

            if(countt.count(s[end]) && window[s[end]]==countt[s[end]]){
                have++;
            }

            while(have==need){//have every char as t //valid substr
                if((end-st+1)<reslen){ //stored 
                    reslen=end-st+1;
                    res={st,end};
                }

                window[s[st]]--;
                if(countt.count(s[st]) && window[s[st]]<countt[s[st]]){//2nd imp 
                     have--;
                }
                st++;
            }
        }

        if(reslen==INT_MAX){
            return "";
        }
        return s.substr(res.first,reslen);







    //    //brute force
    //    if(t.size()==0 || (s.size()<t.size())){
    //     return "";
    //    } 
    //    unordered_map<char,int> countt;
    //    for(int i=0;i<t.size();i++){
    //     countt[t[i]]++;
    //    }

    //    vector<int> res={-1,-1};//for storing best window (st,end)
    //    int reslen=INT_MAX; //to store min length found

    //    for(int st=0;st<s.size();st++){
    //     unordered_map<char,int> counts;
    //      for(int end=st;end<s.size();end++){
    //         counts[s[end]]++;
    //         bool flag=true;
    //         //check if curr substr(st,end) contains all char in t
    //         for(auto e:countt){//{char,freq} //{e.first,e.second}
                //this traversing each and checking in i learned new in map
    //             if(counts[e.first]>=countt[e.first]){
    //               //success
    //               flag=true;
    //             }else{
    //                flag=false;
    //                break;
    //             }
    //         }

    //         if(flag==true){
    //            if((end-st+1)<reslen){
    //             reslen=end-st+1;
    //             res[0]=st;
    //             res[1]=end;
    //            }
    //            break;//now start from next idx
    //         }
    //      }
         
        
    //    }

    //    if(reslen==INT_MAX){
    //     return "";
    //    }
    //    return s.substr(res[0],reslen);

    }
};
