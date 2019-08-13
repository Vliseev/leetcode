
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val = NULL;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            if (!root)
                return true;

            if (!isValidBST(root->left))
                return false;

            if (prev && prev != root && prev->val >= root->val)
                return false;
            prev = root;

            if (!isValidBST(root->right))
                return false;

            return true;
        }

        TreeNode *prev = nullptr;
    };
};

int main() {
    TreeNode *tree_ptr;
    TreeNode tree(10);


    Solution().isValidBST(&tree);

    return 0;
}
