#include <iostream>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr) {};
} ListNode;

// double pointer solution
class Solution{

private:
    ListNode* recur(ListNode* cur, ListNode* pre){
        if(cur == nullptr) return pre;
        ListNode* res = recur(cur -> next, cur);
        cur -> next = pre;
        return res;
    }

public:
    ListNode* reverseList(ListNode* head){
        ListNode* res = recur(head, nullptr);
        return res;
    }

    // using double pointer to reverse the direction of List
    // without using the recursion
    ListNode* reverseList_noRecur(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr){
            ListNode* tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }

};