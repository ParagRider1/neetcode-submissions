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
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> origToCopyMap;
        return dfsReturnCopyNode(node,origToCopyMap);
    }

    Node* dfsReturnCopyNode(Node* orig, map<Node*, Node*> &origToCopyMap){
        if(orig==NULL){
            return NULL;
        }
        if(origToCopyMap.count(orig)){ //copy node already exists 
             return origToCopyMap[orig];
        }

        Node* copy= new Node(orig->val);
        origToCopyMap[orig]=copy;

        //now copy adj neighbor list also
        for(auto neighbor: orig->neighbors){
            copy->neighbors.push_back(dfsReturnCopyNode(neighbor,origToCopyMap));
        }

        return copy;
    }
};
