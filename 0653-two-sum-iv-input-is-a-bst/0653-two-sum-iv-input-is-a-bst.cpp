/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* &root, vector<int> &in){
        if(root == NULL) return;
        solve(root->left,in);
        in.push_back(root->val);
        solve(root->right,in);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        solve(root, in);
        int low = 0;
        int high = in.size() - 1;
        while(low < high){
            if(in[low] + in[high] > k) high--;
            else if(in[low] + in[high] < k) low ++;
            else return true;
        }
        return false;
    }
};