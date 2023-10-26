#include <iostream>
#include <string>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<deque>
#include<stack>
using namespace std;

/*TAKE AWAY
    1. FILO kind of question can use stack
    2. stack fucntions: .push(stuff), .pop(), .emptry(), .top()*/
class Solution {
public:
    bool isValid(string s) {
        //since open bracket has to be closed in CORRECT ORDER
        //stack FILO will help here
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{'  || s[i] == '[' ){
                st.push(s[i]);
            }else{
                if(st.empty()){//helper function st.empty() returns true if empty
                    return false;
                }
                if(s[i] == ')' && st.top() != '('){
                    return false;
                }else if(s[i] == '}' && st.top() != '{'){
                    return false;
                }else if(s[i] == ']' && st.top() != '['){
                    return false;  
                }

                st.pop();
            }
        }
        return st.empty();
    }
};