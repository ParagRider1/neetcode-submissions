class Solution {
public://reverse polish notation == postfix expression
    //we have to use stack 
    //not pq,not map,not set, not queue, not ll
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/" ){
                s.push(stoi(tokens[i]));
            }else{
                //NOTE
                // the first item you pop is the right operand, and the second item you pop is the left operand. 
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                if(tokens[i]=="+"){
                    res=op1+op2;
                }else if(tokens[i]=="-"){
                    res=op1-op2;
                }else if(tokens[i]=="*"){
                    res=op1*op2;
                }else{
                    res=op1/op2;
                }

                s.push(res);
            }
        }
        return s.top();
    }
};
