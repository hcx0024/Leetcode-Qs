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

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0 && m == 0){
            //nums1 = [];
        }else if(m == 0){
            nums1 = nums2;
        }else if(n == 0){

        }else{
            vector<int> temp;
            for(int i = 0; i < m; i++){
                temp.push_back(nums1[i]);
            }
            for(int i = 0; i < n; i++){
                temp.push_back(nums2[i]);
            }
            sort(temp.begin(), temp.end());
            nums1 = temp;
        }

    }
};