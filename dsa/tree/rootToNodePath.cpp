#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    bool getPath(TreeNode* root, vector<int> &arr, int x) {
        if(!root) return false;
        arr.push_back(root->val);
        if(root->val == x) return true;
        if(getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true;
        arr.pop_back();
        return false;
    }

    vector<int> rootToNodePath(TreeNode* A, int B) {
        vector<int> arr;
        if(!A) return arr;
        getPath(A, arr, B);
        return arr;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    int target;
    cin >> target;
    Solution s;
    vector<int> path = s.rootToNodePath(root, target);
    // reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}