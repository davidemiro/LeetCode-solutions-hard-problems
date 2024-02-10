/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    

    vector<Node*> nodes;
    Node* cloneGraphRec(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        Node* copy = new Node(node->val);
        nodes[node->val] = copy;
        for(Node* n : node->neighbors){
            if(nodes[n->val] == nullptr){
                copy->neighbors.push_back(cloneGraphRec(n));
            }
            else{
                copy->neighbors.push_back(nodes[n->val]);
            }
        }
        
        return copy;
        
    }
    Node* cloneGraph(Node* node) {
        nodes = vector<Node*>(101);
        for(int i = 0; i < 100; i++){
            nodes[i] = nullptr;
        }
        
        return cloneGraphRec(node);
  
        
    }
};