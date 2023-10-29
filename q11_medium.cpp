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
/*Container With Most Water
    [1, 8, 6, 7, 6, 7]
     head            tail
     traverse and move the one poiting smaller head to next
     get each volume and keep updating max*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2){
            return 0;
        }
        
        int head = 0;
        int tail = height.size()-1;
        int maxWater = 0;
        while(1){
            if(head == tail || tail < head){
                break;
            }
            int tempW = 0;
            if(height[head] >= height[tail]){
                tempW = height[tail] * (tail - head);
            }else{
                tempW = height[head] * (tail - head);
            }
            if(tempW > maxWater){
                maxWater = tempW;
            }
            if(height[head] > height[tail]){
                tail--;
            }else{
                head++;
            }
        }
        return maxWater;
        
    }
};