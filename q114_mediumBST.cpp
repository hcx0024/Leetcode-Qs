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
    Question asks to turn a binary tree to linked list
    1. use a vector to store pointers
    2. if NULL then return, 
       if not first record all left nodes and then all right nodes
    3. traverse through the vector, link all of them */
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
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> nodes;
        flattenHelper(root, nodes);

        for(int i = 0; i < nodes.size()-1; i++){
            nodes[i]->right = nodes[i+1];
            nodes[i]->left = NULL;
        }
        return;
    }

    void flattenHelper(TreeNode* root, vector<TreeNode*>& nodes){
        if(root == NULL) return;
        nodes.push_back(root);
        flattenHelper(root->left, nodes);
        flattenHelper(root->right, nodes);
        
    
    }
};