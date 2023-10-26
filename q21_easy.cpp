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

/*TALE AWAY
    1. linked list
    2. if merge l2 to l1, temp = l1.next, l1.next = l2, l2 = l2->next[MUST update], l1->next->next = temp 
    3. MUST REVIEW BEFORE OA/INTERVIEW*/
struct ListNode {
    int val;
    ListNode *next;
 };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        ListNode* headd = NULL;
        ListNode* curr1 = NULL;
        ListNode* curr2 = NULL;

        //the goal is to merge curr2 into curr1
        //first assign headd for later return purpose
        //who ever has smaller starting value is curr1
        if(list1->val <= list2->val){
            curr1 = list1;
            curr2 = list2;
        }else{
            curr1 = list2;
            curr2 = list1;
        }
        headd = curr1;
        //now make sure that curr1->next is not empty
        if(curr1->next == NULL){
            curr1->next = curr2;
            return curr1;
        }
        //1 2 8 9|| 1 3 4
        while(curr1 != NULL && curr2 != NULL){
           //case1 curr1 next is NULL
           if(curr1->next == NULL){
               curr1->next = curr2;
               curr1 = NULL;//force quit
           }else if(curr1->next->val >= curr2->val){//case2 curr1->next.val >= curr2.val
               ListNode* tempNode = curr1->next;//e.g. save 2->8->9
               curr1->next = curr2;//1->1
                curr2 = curr2->next;//3->4 curr2 MUST to be updated here
                //lets say curr2 ->1 rn, if we dont update then the next line will assign curr2->next->2 in curr1
               curr1->next->next = tempNode;//1->1->2->8->9
              
               
           }else{ //case3 curr1->next.val < curr2.val
               curr1 = curr1->next;
           }
        }
        return headd;
    }
};