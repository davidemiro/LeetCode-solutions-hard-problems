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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        
        ListNode* pointer = nullptr;
        ListNode* finalList = nullptr;
        heap_build(lists,n);
        while(true){
            if(lists[0] == nullptr) break;
            if(lists[0]->val == 10001) break;
            if(pointer == nullptr){
                pointer = new ListNode();
                finalList = pointer;
                
                
            }
            else{
                pointer->next = new ListNode();
                pointer = pointer->next;
            }
            
            pointer->val = lists[0]->val;
            
            if(lists[0]->next == nullptr){
                lists[0] = new ListNode(10001);
            }
            else{
                lists[0] = lists[0]->next;
            }
            heapify(lists,0,n);
            
        }
        return finalList;
        
        
    }
    void heap_build(vector<ListNode*>& heap,int n){
        for(int i = (n / 2) - 1; i >= 0; i--){
            heapify(heap,i,n);
        }
        
    }
    void heapify(vector<ListNode*>& heap, int i, int n){
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        ListNode* tmp;
        if(heap[i] == nullptr){
            heap[i] = new ListNode(10001);
        }
        
        
        if(left < n && heap[left] == nullptr){
            heap[left] = new ListNode(10001);
        }
        if(right < n && heap[right] == nullptr){
            heap[right] = new ListNode(10001);
        }
        if(left < n && heap[left]->val < heap[i]->val){
            tmp = heap[i];
            heap[i] = heap[left];
            heap[left] = tmp;
            heapify(heap,left,n);
        }
        if(right < n && heap[right]->val < heap[i]->val){
            tmp = heap[i];
            heap[i] = heap[right];
            heap[right] = tmp;
            heapify(heap,right,n);
        }
        
        
       
    }
};