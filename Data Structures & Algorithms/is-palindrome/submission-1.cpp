class Solution {
public:
    bool isPalindrome(string s) {
        string news="";
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 && s[i]<=90){
                news+=(char)((s[i]-'A')+97); //lowercase
            }
            else if(s[i]==' '){
                continue;
            } else if( (s[i]>=97 && s[i]<=122) || (s[i]-'0'>=0 && s[i]-'0'<=9)){
                news+=s[i];
            }   
        }
        int st=0;int end=news.size()-1;
        while(st<=end){
            if(news[st]!=news[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
        // string revnews=news;
        // reverse(revnews.begin(),revnews.end());

        // if(news==revnews){
        //     return true;
        // }
        // return false;
    }
};
