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
    1. This question asks for group of anagrams
    2. Use UNORDERED MAP to build hash table, key:sorted string, value: string itself
    3. solve collision by chaining
    4. unordered_map<string, vector<string>> is the way to construct
    5. if what to find the info we stored earlier in the un ordered map
        USE for (auto&pair : <map name>)
        pair.first is key, in this case string
        pair.second is the stored value, in this case vector<string>
        */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashTable;
        vector<vector<string>> returnVec;
        for(int i = 0; i < strs.size(); i++){
            string currStr = strs[i];
            sort(currStr.begin(), currStr.end());
            hashTable[currStr].push_back(strs[i]);
        }
        for(auto&pair:hashTable){
            returnVec.push_back(pair.second);
        }
        
        return returnVec;
    }
};