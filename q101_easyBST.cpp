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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* root1, TreeNode* root2){
        //root1 NULL && root2 NULL -> TRUE
        if(!root1 && !root2) return true;
        //root1 or root2 NULL -> FALSE
        if(!root1 || !root2) return false;
        //root1 value != root2 value -> FALSE
        if(root1->val != root2->val) return false;
        //root1->right != root2->left FALSE

        //root1->left != root2->right FALSE

        //return isMirror root1left root2right && root1right root2left
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
};