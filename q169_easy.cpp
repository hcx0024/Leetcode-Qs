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
    1. Moore's Voting Algorithm
        a cool algorithm which we think the way of having credit
        set a curr number, if it appears after sets, credit it for 1, not appear once decredit for 1
        think in this way
        we know there will be a value appearing more than n/2 times, this num will have enough credit to survive to the end
        00112111
        cot=1,el=0 || cot=2,el=0 || cot=1,el=0 || cot=0,el=0 || cot=1,el=2 ||  cot=0,el=2 ||  cot=1,el=1 || cot=2,el=1 ||
        0101011
    2. BTW, vec[i] works
    */
    
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore's Algorithm
        //cot = count of appearance / credit of appeaerance as appear+1 & not appear-1
        //el is curr element appears
        int cot = 0;
        int el = 0;
        for(int i = 0; i < nums.size(); i++){
            if(cot == 0){
                //update el
                el = nums[i];
            }

            if(el == nums[i]){
                cot++;
            }else{
                cot--;
            }
        }
        return el;
    }

};