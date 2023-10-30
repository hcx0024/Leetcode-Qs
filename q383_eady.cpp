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
    1. used unordered map:
        a. Initialization is unordered_map<char, int> name
        b. when initialize everything is 0
        c. no resize needed, dynamic*/
        
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> charToAppearTime;
        for(int i = 0; i < magazine.length(); i++){
            charToAppearTime[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            charToAppearTime[ransomNote[i]]--;
            if(charToAppearTime[ransomNote[i]] < 0){
                return false;
            }
        }
        return true;
    }
};