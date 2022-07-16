#include <iostream>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val), left(NULL), right(NULL){}
}TreeNode;


//interesting recursion
// common way to resoulve the problem of binary tree

class Solution{

private:
    bool recur(TreeNode* L, TreeNode* R){
        if(L == nullptr && R == nullptr) return true;
        if(L == nullptr || R == nullptr || L -> val != R -> val) return false;
        return recur(L -> left, R -> right) && recur(L -> right, R -> left);
    }

public:
    bool isSymmetric(TreeNode* root){
        if(root == NULL) return true;
        return recur(root -> left, root -> right);
    }

};