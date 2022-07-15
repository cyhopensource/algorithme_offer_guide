#include <iostream>

using namespace std;

// Depth first research
typedef struct TreeNode{
    int val;
    TreeNode* leftNode;
    TreeNode* rightNode;
    TreeNode(int _val):val(_val), leftNode(NULL), rightNode(NULL) {}
}TreeNode;

class Solution{

private:
    bool recur(TreeNode* node_a, TreeNode* node_b){
        if(node_b == nullptr) return true;
        if((node_a == nullptr) || (node_a -> val != node_b -> val)) return false;
        return recur(node_a -> rightNode, node_b -> rightNode) && recur(node_a -> leftNode, node_b -> leftNode);
    }

public:
    bool isSubTree(TreeNode* A, TreeNode* B){
        if(A == nullptr || B == nullptr)
            return;

        return (recur(A, B) || isSubTree(A -> leftNode, B) || isSubTree(A -> rightNode, B));
        
    }

};