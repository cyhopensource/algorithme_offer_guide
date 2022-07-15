#include <iostream>
#include <stack>

using namespace std;

// this question has two methods
// 1: recur DFS
// 2: auxilary stack

typedef struct TreeNode{
    int val;
    TreeNode* leftNode;
    TreeNode* rightNode;
    TreeNode(int _val):val(_val), leftNode(NULL), rightNode(NULL){}
}TreeNode;


class Solution{

private:
    void recur(TreeNode* node){
        if(node == nullptr)
            return;
        if((node -> leftNode != nullptr) || (node -> rightNode != nullptr)){
            TreeNode* tmp = nullptr;
            tmp = node -> leftNode;
            node -> leftNode = node -> rightNode;
            node -> rightNode = tmp;
            recur(node -> leftNode);
            recur(node -> rightNode);
        }else
            return;
    }

public:
    TreeNode* mirrorTree(TreeNode* root){
        if(root == nullptr) return root;
        recur(root);
        return root;
    }
        
    TreeNode* mirrorTree_stack(TreeNode* root){
        
    }

};




