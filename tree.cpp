



#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class TreeNode {
private:
    int val;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int val, TreeNode& left, TreeNode& right): val(val), left(nullptr), right(nullptr){}
};
// 


// 二叉树的迭代遍历

// 前序遍历
class Solution0 {
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);
        if(root == NULL){
            return result;
        }
    }
};