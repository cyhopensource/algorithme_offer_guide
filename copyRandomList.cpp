#include <iostream>
#include <unordered_map>

using namespace std;

// The idea of mapping HashMap
// Can map everything !!
typedef struct Node{
    int val;
    Node* next;
    Node* random;

    Node(int _val){
        val = _val;
        next = nullptr;
        random = nullptr;
    }

}Node;

class Solution{

public:

    Node* copyRandomList(Node* head){
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;

        // set up the mapping between the current pointer and new pointer.
        while(cur != nullptr){
            map[cur] = new Node(cur -> val);
            cur = cur -> next;    
        }

        cur = head;
        while(cur != nullptr){
            map[cur] -> next = map[cur -> next];
            map[cur] -> random = map[cur -> random];
            cur = cur -> next;
        }

        return map[head];
    }
    

};