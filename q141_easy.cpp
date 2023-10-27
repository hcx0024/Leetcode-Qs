#include <iostream>
#include <string>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<deque>
#include<stack>
using namespace std;
/*TAKE AWAY
    1. Tortoise and Hare Algorithm
        two ptr runs on track, fast and slow
        fast move 2 steps
        slow move 1 step
        if match, true
        if any gets to NULL, false
    2. Careful when doing fast->next->next since fast->next could be NULL
    3. Careful handling base cases, list size = [], [1], [1,2]*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*Tortoise and Hare Algorithm*/
        //Have a faster pointer run 2 steps a time
        //have a slow pointer runs 1 step a time
        //if matches, return true
        //if get to NULL, return false
        
        //first start with handling base cases
        if(head == NULL){//if list is NULL
            return false;
        }
        if(head->next == NULL){//list only have 1 element
            return false;
        }

        //set up fast ptr and slow ptr
        ListNode* fast = head;
        ListNode* slow = head;
        while(1){
            //first check no one is NULL
            if(fast == NULL || slow == NULL){
                return false;
            }
            //let fast run 1
            fast = fast->next;
            //check if fast has a next loc to go
            if(fast == NULL || fast->next == NULL){
                return false;
            }else{//yes there is still stuff
                fast = fast->next;
            }
            //then have slow to run
            //no concerns since slow only go one step
            slow = slow->next;
            //if fast catched up, loops
             if(fast == slow){
                return true;
            }
        }
    }
};