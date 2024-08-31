
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(stack<int> st, int n){
    for(int i = 0; i < n; i++){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// APPROACH 1
// void reverse(stack<int>& st){
//     if(st.empty())
//         return;
        
//     int top = st.top();
//     st.pop();
//     reverse(st); 
    
//     // pushing all the remaining elements of st to temp
//     stack<int> temp;
//     while(!st.empty()){
//         temp.push(st.top());
//         st.pop();
//     }
    
//     // when st becomes empty then put top to it (so it is at the bottom)
//     st.push(top);
    
//     // then again put all the elements to st from temp
//     while(!temp.empty()){
//         st.push(temp.top());
//         temp.pop();
//     } 
// }


// APPROACH 2 
void insertAtBottom(stack<int>& st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    
    int top = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(top);
}
void reverse(stack<int>& st){
    if(st.empty())
        return;
    
    int top = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, top);
}
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    int n = 5;
    
    print(st, st.size());
    
    reverse(st);
    cout << endl;
    
    print(st, st.size());
}
