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
    1. ask for a full path as root to leaves, so if sum at certain pt greater than target sum return false
    2. go all the way to the end then do sum checking*/
    
struct TreeNode {
    int val;
    TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return hasPathSumHelper( root,  targetSum,0);
        
    }
private:
    bool hasPathSumHelper(TreeNode* root, int targetSum, int currSum) {
        if(!root){
            //if(currSum == targetSum) return true; 
            return false;
        }
        if(!root->right && !root->left){//leave
            currSum += root->val;
            if(currSum == targetSum){
                return true;
            }else{
                return false;
            }
        }

        currSum += root->val;
        return hasPathSumHelper(root->left, targetSum, currSum) ||  hasPathSumHelper(root->right, targetSum, currSum);


        
        
    }
};