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
    Question given preorder and inorder of a tree, ask to construct a tree
    1. first use an unordered map to store each node to its index in inorder vector
    2. preorder: root left right | inorder: left root right
    3. for each iteration, take the first of preorder as root(preorder property)
       find its index in inorder and get the left child[rootIndex-1] and right child[rootIndex+1]
    4. Recursive calls:
        - preStart: root index in preorder
        - inStart: starting index in inorder
        - inEnd: ending index in inorder 
        every call:
            I. check if indexes are in bound
            II. new a root since we knoe the value of node
            III. get this curr root's index, for next call
            IV. set it left & right child by putting new prestart in and new inStart inEnd in 
*/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> value_to_inIndex;
        for(int i = 0; i < inorder.size(); i++){
            value_to_inIndex[inorder[i]] = i;
        }

        return buildTreeHelper( preorder, inorder, 0, 0, inorder.size()-1, value_to_inIndex);

    }
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd, unordered_map<int, int>& value_to_inIndex){
        if(preStart >= preorder.size() || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = value_to_inIndex[preorder[preStart]];

        root->left = buildTreeHelper( preorder, inorder, preStart+1, inStart, rootIndex-1, value_to_inIndex);//left
        root->right = buildTreeHelper( preorder, inorder, preStart + rootIndex - inStart + 1, rootIndex+1, inEnd, value_to_inIndex);//r
        return root;

    }
};