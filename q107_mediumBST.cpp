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
//queue: FIFO
//unordered map: key to value
//vector: push back pop back
//stack: LIFO

/*TAKE AWAY
    1. use a queue to record data
    2. root: push root on and push an NULL indicating this level is ended
    3. Other levels: pop one from previous level and push all of its child on, until reached to a NULL indicating previous level ends and this level also ends*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(1){
            Node* n = q.front();
            if(n){//not NULL, still at this level
                q.pop();
                n->next = q.front();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }else{
                q.pop();
                if(q.empty()) break;
                q.push(NULL);//curr level end
            }
        }
        return root;
    }


};