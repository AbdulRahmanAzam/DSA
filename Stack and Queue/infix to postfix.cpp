#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c){
    if(c == '^')
        return 3;
    else if(c == '*' or c == '/')
        return 2;
    else if(c == '+' or c == '-')
        return 1;
    
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string res;
    
    for(int i = 0; i < s.size(); i++){
        if(('A' <= s[i] && s[i] <= 'Z') or ('a' <= s[i] && s[i] <= 'z')){
            res += s[i]; 
            
        }else if(s[i] == '('){
            st.push(s[i]);
            
        }else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res+= st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
            
        }else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}



int main() {
    cout << "The Postfix of Infix K+L-M*N+(O^P)*W/U/V*T+Q is:  " << infixToPostfix("K+L-M*N+(O^P)*W/U/V*T+Q") << endl;
    
    
    // cout << "(a-b/c)*(a/k-l):  " << infixToPostfix("(a-b/c)*(a/k-l)");
}
