/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<pair<int,Node*>>  q;
        pair<int,Node*> p,pred;
        q.emplace(pair<int,Node*>(1,root));
        while(!q.empty()){
            
            p = q.front();
            q.pop();
            if(p.second == nullptr) break;
            if(p.first == 1) pred = p;
            else{
                if(p.first == pred.first){
                    pred.second->next = p.second;
                }
                
            }
            if(p.second->left != nullptr && p.second->right != nullptr){
                q.emplace(pair<int,Node*>(p.first + 1,p.second->left));
                q.emplace(pair<int,Node*>(p.first + 1,p.second->right));
            }
            pred = p;
            
        }
        
        return root;
        
        
    }
};