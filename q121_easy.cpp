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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int left = 0;
        int right = 1;
       while(right < prices.size() && left < prices.size()){
           if(prices[right] - prices[left] <= 0){
               left = right;
               right = left+1;
           }else{
               int tempP = prices[right] - prices[left];
                    if(tempP > maxProfit){
                        maxProfit = tempP;
                    }
               right++;
           }
       }

        
        return maxProfit;

    }
};