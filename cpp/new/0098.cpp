
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    if (!root) {
      return true;
    }

    if (!isValidBST(root->left)) {
      return false;
    }

    cout << root->val << "\n";

    if (last && last != root && last->val >= root->val) {
      return false;
    }

    last = root;

    if (!isValidBST(root->right)) {
      return false;
    }

    return true;
  }

 private:
  TreeNode *last = nullptr;
};

int main() {
  TreeNode *tree_ptr;
  TreeNode tree(10);


  Solution().isValidBST(&tree);

  return 0;
}
