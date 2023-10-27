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
    1. idea here is to have two stack
        [2 9 7 -1 2 -3 -6 18] actual stack
        [2 2 2 -1 -1 -3 -6 -6] stack keeping track of current min
    2. stack functions
        push()
        pop()
        top()
        empty() returns 1 if stack empty
    */
class MinStack {
public:
    stack<int> minSt, st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()){
            minSt.push(val);
        }else{
            if(minSt.top() >= val){//made a mistake here, only make changes when mintop value is greater than input val 
                minSt.push(val);
            }else{
                int top = minSt.top();
                minSt.push(top);
            }
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
