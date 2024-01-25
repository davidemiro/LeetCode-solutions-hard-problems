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
    ListNode* resultListNode(ListNode* l1, ListNode* l2,int r){
        
        if(l1->next ==nullptr && l2->next == nullptr){
            int sum = l1->val + l2->val + r;
            if(sum > 9){
                r = sum / 10;
                sum = sum % 10;
                
                return new ListNode(sum,new ListNode(r));
            }
            else
                return new ListNode(sum);
        }
        else{
            int sum = l1->val + l2->val + r;
            if(sum > 9){
                r = sum / 10;  
                sum = sum % 10;
                 
            }
            else
                r = 0;
            return new ListNode(sum,resultListNode(l1->next,l2->next,r));
        }
    }
    ListNode* addZeros(ListNode* l,int N){
        ListNode* n = l;
        while(l->next != nullptr){
            l = l->next;
        }
        for(int i = 0; i < N; i++){
            l-> next = new ListNode(0);
            l = l->next;
        }
        return n;
    }
    int countNode(ListNode* l){
        int N = 0;
        while(l != nullptr){
            N++;
            l = l->next;
        }
        return N;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int N1 = countNode(l1);
        int N2 = countNode(l2);
        
        l1 = N1 >= N2 ? l1 : addZeros(l1,N2 - N1);
        l2 = N2 >= N1 ? l2 : addZeros(l2,N1 - N2);
        
        ListNode* sum =resultListNode(l1,l2,0);
        
        return sum;
        
        
        
    }
};