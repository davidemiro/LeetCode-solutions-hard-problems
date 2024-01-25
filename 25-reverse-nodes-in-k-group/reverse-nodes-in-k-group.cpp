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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* it = head;
        vector<ListNode*> g(k);
        int tmp;
        int i = 0;
        while(it != nullptr){
            
            g[i] = it;
            it = it->next;
            i++;
            if(i == k){
                for(int j = 0; j < k / 2; j++){
                    tmp = g[j]->val;
                    g[j]->val = g[k - j - 1]->val;
                    g[k - j - 1]->val = tmp;
                    
                }
                i = 0;
            }
        }
        
        return head;
    }
};