#include <iostream>
#include <string>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<deque>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;

/*TAKE AWAY
    1. vector is a powerful data structure
        find(vec.begin(), vec.end(), item) == vec.end() indicating not find this number
    */

class Solution {
public:
    bool isHappy(int n) {
        if(n == 1){
            return true;
        }
        vector<int> visitedNum;
        while(true){
            int temp = 0;
            while(n>0){
                temp = temp + pow(n%10, 2);
                n = n /10;
            }
            n = temp;
            if(n == 1){
                break;
            }
            if(find(visitedNum.begin(), visitedNum.end(), n) == visitedNum.end()){
                visitedNum.push_back(n);
            }else{return false;}
            
           
        }
        return true;
        
    }
};