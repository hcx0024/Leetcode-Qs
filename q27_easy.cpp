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

/*Question asked to remove element from array, e.g. [3,2,2,3] val = 3 return 2 and change array to [2,2,_,_]

TAKE AWAY:
1.Think smart if wnat us to give an k and set nums is non-val till k. 
                have an index = 0 and traverse array, assign nums[index] every time find one non val in nums*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        
        return index;
    }
};