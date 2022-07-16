#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val), left(NULL), right(NULL){}
}TreeNode;


// use queue to realize the BFS
// use recursion to realize the DFS (e.g., mirror tree, isSymmetricBinTree)

// the exercise: utilize the feature of queue
// need to really understand the <queue>: layer per layer

// queue is always used in mission queue
class Solution{

public:
    vector<int> levelOrder(TreeNode* root){
        vector<int> res;
        if(root == nullptr) return res;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while(!node_queue.empty()){
            TreeNode* front_node = node_queue.front();
            node_queue.pop();
            res.push_back(front_node -> val);
            if(front_node -> left != nullptr) node_queue.push(front_node -> left);
            if(front_node -> right != nullptr) node_queue.push(front_node -> right);
        }

        return res;
    }

    // the different layer of queue
    vector<vector<int>> levelOrder_2(TreeNode* root){
        vector<vector<int>> res;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while(!node_queue.empty()){
            vector<int> tmp;
            for(int i = node_queue.size(); i < 0; i--){
                TreeNode *front_node = node_queue.front();
                tmp.push_back(front_node -> val);
                if(front_node -> left != nullptr) node_queue.push(front_node -> left);
                if(front_node -> right != nullptr) node_queue.push(front_node -> right);
            }
            res.push_back(tmp);
        }
        return res;
    }


};


