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

/*
Question: JUMP GAME. You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/
/*TAKE AWAY
    
    1.case 1: arrive at a position with value 0: return false cuz no further move can be make
        plz note that this works cuz we loop till second last variable
    2.case 2: at certain value, cannot move to max step cuz max step is 0, like at 3 on [3,2,2,0,1]
    3.case 3: at certain vaule, can move to max step
    */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() < 2) return true;
        int currPos = 0;
        while(currPos < nums.size()-1){
            if(nums[currPos] == 0) return false;
            int step = currPos;
            int maxStep = currPos + nums[currPos];
            if(nums[maxStep] == 0 ){
                step++;
                while(step < maxStep){
                    if(nums[step] != 0) break;
                    step++;
                }
            }else{
                step = maxStep;
            }
            
            currPos = step;
        }
        return true;
    }
};