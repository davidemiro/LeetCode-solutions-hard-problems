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
    ListNode* reverseListSol(ListNode* head, ListNode* newNext) {
        if(head == nullptr){
            return nullptr;
        }else if(head->next == nullptr){
            head->next = newNext;
            return head;
        }else{
            ListNode* newHead = reverseListSol(head->next, head);
            head->next = newNext;
            return newHead;
        }
        
    }
    ListNode* reverseList(ListNode* head) {
        return reverseListSol(head,nullptr);
        
    }
};