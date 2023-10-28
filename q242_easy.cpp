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
using namespace std;

/*TAKE AWAY
    1. use sort for vector and string
    2. sort():
        array:
            Here we take two parameters, the beginning of the
            array and the length n upto which we want the array to
            be sorted
            sort(arr, arr + n);
        string:
            sort(s.begin(), s.end());
        vector:
            sort(vec.begin(), vec.end());*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t){
            return true;
        }
        return false;
    }
};