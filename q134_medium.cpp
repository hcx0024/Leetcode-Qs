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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startingIndex = 0;
        int totalGas = 0;
        int totalCost = 0;
        int currGas = 0;
        
        int n = gas.size();
        for(int i = 0; i < n; i++){
            //record total gas and total cost
            totalGas += gas[i];
            totalCost += cost[i];
            //record curr starting position
            /*IDEA HERE
                curr gas is += curr gas - curr cost to next
                the car can only reach to next iff the gas is >= 0 
                (why equal to? we here delete the cost to next first so even if = 0 can also reach to next)
                IF the curr gas is negative meanning that from staring to i is not reachable so starting point is i + 1
                (WHY i+1 not i, because if A cannot reach A' anything before A' cannot go to A', only after A' might have a path to A')*/
            currGas = gas[i] - cost[i] + currGas;
            if(currGas < 0){
                currGas = 0;
                startingIndex = i+1;
            }
        }
        if(totalGas < totalCost) return -1;//if total gas < total cost then there is never an solution
        return startingIndex;
        
    }

    
};