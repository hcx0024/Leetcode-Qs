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
    1. comparing two tree, ask if structurally the same
        - consider all possible cases
            - p = q -> keep finding p.left, q.left and p.right, q.right
            - p value != q value -> false
            - p Null or q NULL -> false
            - p and q both NULL, true
    2. use recursion and && to find solution for both left side and right side*/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //four cases
        //q and p both NULL, true
        if(!p && !q) return true;//!p = NULL
        //q or p is NULL, false
        if(!p || !q) return false;
        //q and p not equal. false
        if(p->val != q->val) return false;
        //q and p equal, keep finding
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};