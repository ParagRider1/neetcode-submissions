class Solution {
public:
    bool isValidRow(int i,vector<int> &rowValid,vector<vector<char>>& board){
        unordered_map<char,int> freq;
        for(int j=0;j<9;j++){
           if(board[i][j]!='.'){
              if(freq[board[i][j]]!=1){
              freq[board[i][j]]++;
              }else{
                return false;
              }
           }
        }
        rowValid[i]=1;
        return true;
    }

    bool isValidCol(int j,vector<int> &colValid,vector<vector<char>>& board){
        unordered_map<char,int> freq;
        for(int i=0;i<9;i++){
           if(board[i][j]!='.'){
              if(freq[board[i][j]]!=1){
              freq[board[i][j]]++;
              }else{
                return false;
              }
           }
        }
        colValid[j]=1;
        return true;
    }
    bool isValidbox(int boxNo,vector<int> &boxValid,vector<vector<char>>& board){
        unordered_map<char,int> freq; //let boxNo =2
        int ist=(boxNo/3)*3; //0
        int iend=ist+3;
        int jst=(boxNo%3)*3; //3
        int jend=jst+3;

        for(int i=ist;i<iend;i++){
            for(int j=jst ;j<jend;j++){
                if(board[i][j]!='.'){
                    if(freq[board[i][j]]!=1){
                    freq[board[i][j]]++;
                    }else{
                        return false;
                    }
                }
            }
        }
        boxValid[boxNo]=1;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= board.size();
        vector<int> rowValid(n,0);
        vector<int> colValid(n,0);
        vector<int> boxValid(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    if(rowValid[i]!=1){
                      if(isValidRow(i,rowValid,board)==false){
                        return false;
                      }
                    }
                    if(colValid[j]!=1){
                     if(isValidCol(j,colValid,board)==false){
                        return false;
                     }
                    }
                    int boxNo= ((i/3)*3) +(j/3);
                    if(boxValid[boxNo]!=1){
                     if(isValidbox(boxNo,boxValid,board)==false){
                        return false;
                     }
                    }
                }
            }
        }

        return true;
    }
};
