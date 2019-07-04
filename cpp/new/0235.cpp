#include<vector>
#include<iostream>
#include<bitset>
#include<queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


using namespace std;

   vector<TreeNode*> pathToNode(TreeNode* root, TreeNode* node){
    std::vector<TreeNode*> result;
    while(root != null){
      result.push_back(root);
      if(root == node)
        break;
      root = root->val > node->val ? root->left : root->right; 
    }
    return result;
   }

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      auto s = min(p->val, q->val);
      auto b = max(p->val, q->val);
      
      auto p_path = pathToNode(root, p);
      auto q_path = pathToNode(root, q);
      
      if (p_path.size()<q_path.size()){
          while(p_path.size()<q_path.size())
            q_path.pop_back();
      } else if(p_path.size()>q_path.size()){
          while(p_path.size()>q_path.size())
            p_path.pop_back();
      }
                  
      
      return result;
    }
};

int main() {
  TreeNode *tree_ptr;
  TreeNode tree(10);

  tree_ptr = &tree;

  tree_ptr->left = new TreeNode(8);
  tree_ptr->right = new TreeNode(15);

  tree_ptr = tree.left;

  tree_ptr->left = new TreeNode(3);
  tree_ptr->right = new TreeNode(9);

  tree_ptr = tree_ptr->left;

  tree_ptr->left = new TreeNode(1);
  tree_ptr->right = new TreeNode(4);

  tree_ptr = tree_ptr->left;

  tree_ptr->left = new TreeNode(-1);
  tree_ptr->right = new TreeNode(2);

  tree_ptr = tree.right;

  tree_ptr->left = new TreeNode(12);
  tree_ptr->right = new TreeNode(17);
  tree_ptr->left->left = new TreeNode(11);

  tree_ptr = tree_ptr->right;
  tree_ptr->left = new TreeNode(16);
  tree_ptr->right = new TreeNode(18);

  auto res = Solution().levelOrder(&tree);
  
  for(const auto &level: res){
    for(const auto &el: level){
      cout<<el<<" ";
    }
    cout<<"\n";
  }

  return 0;
}

