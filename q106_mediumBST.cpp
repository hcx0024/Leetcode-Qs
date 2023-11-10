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
    Question given postorder and inorder of a tree, ask to construct a tree
    1. first use an unordered map to store each node to its index in inorder vector
    2. postorder: left right root | inorder: left root right
    3. for each iteration, take the last of postorder as root(postorder property)
       find its index in inorder and get the left child[rootIndex-1] and right child[rootIndex+1]
    4. Recursive calls:
        - posStart: root index in postorder
        - inStart: starting index in inorder
        - inEnd: ending index in inorder 
        every call:
            I. check if indexes are in bound
            II. new a root since we knoe the value of node
            III. get this curr root's index, for next call
            IV. set it left & right child by putting new prestart in and new inStart inEnd in 

    5. how to update, given root in postorder
        - next left child as root: postIndex - everything on right side = postIndex - inorder.size() + rootInorderIndex -1
        - next right child as root: postIndex - 1
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> value_to_inIndex;
        if(inorder.size() == 0 || postorder.size() == 0) return NULL;
        for(int i = 0; i < inorder.size(); i++){
            value_to_inIndex[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, postorder, postorder.size()-1, 0, inorder.size()-1, value_to_inIndex);

    }
private:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int posStart, int inStart, int inEnd,  unordered_map<int,int>& value_to_inIndex){
        if(posStart < 0 || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[posStart]);
        int rootIndex = value_to_inIndex[postorder[posStart]];//where this root is at inorder
        root->right = buildTreeHelper(inorder, postorder, posStart-1, rootIndex+1, inEnd, value_to_inIndex);//right 
        root->left = buildTreeHelper(inorder, postorder, posStart-inEnd+rootIndex-1, inStart, rootIndex-1, value_to_inIndex);//left
        return root;
    }
};