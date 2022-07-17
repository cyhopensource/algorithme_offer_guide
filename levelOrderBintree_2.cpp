#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// using the dequeue data structure
// Actually it's a double stack

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val), left(NULL), right(NULL){}
}TreeNode;

class Solution{

public:
    vector<vector<int>> levelOrderBinTree(TreeNode* root){
        vector<vector<int>> res;
        deque<TreeNode*> node_queue;
        if(root == nullptr) return res;
        node_queue.push_back(root);
        while(!node_queue.empty()){
            vector<int> tmp;
            for(int i = node_queue.size(); i > 0; i--){
                TreeNode* node_front = node_queue.front();
                node_queue.pop_front();
                tmp.push_back(node_front -> val);
                if(node_front -> left != nullptr) node_queue.push_back(node_front -> left); 
                if(node_front -> right != nullptr) node_queue.push_back(node_front -> right);
            }
            res.push_back(tmp);
            if(node_queue.empty()) break;
            tmp.clear();
            for(int i = node_queue.size(); i > 0; i--){
                TreeNode* node_back = node_queue.back();
                node_queue.pop_back();
                tmp.push_back(node_back -> val);
                if(node_back -> right != nullptr) node_queue.push_front(node_back -> right);
                if(node_back -> left != nullptr) node_queue.push_front(node_back -> left);
            }
        }
        return res;
    }

};


