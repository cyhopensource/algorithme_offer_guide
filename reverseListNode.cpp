#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// take advantage of Stack data structure
typedef struct ListNode{
    int val;
    ListNode* next;
    // initialise the Node.
    ListNode(int x): val(x), next(nullptr) {}
};


class Solution{

private:
    vector<int> res;
    void recur(ListNode* node){
        if(node == nullptr) return;
        recur(node -> next);
        res.push_back(node -> val);
    }

public:

    // method of regression
    vector<int> reversePrint(ListNode* head){
        recur(head);
        return res;
    }

    // method of auxilary stack
    vector<int> reversePrint_Stack(ListNode* head){
        vector<int> res;
        stack<int> stk;
        while(head != nullptr){
            stk.push(head->val);
            head = head -> next;
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
        
    }

};