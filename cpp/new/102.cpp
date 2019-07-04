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
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> result;
      queue<TreeNode *> que;
      que.push(root);
      
      while(!que.empty()){
        vector<int> cur_level;
        int size=que.size();
        for(auto i=0; i<size;i++){
          auto el = que.front();
          que.pop();
          cur_level.push_back(el->val);
          
          if(el->left!=nullptr)
            que.push(el->left);
          if(el->right!=nullptr)
            que.push(el->right);          
        }
        result.push_back(move(cur_level));
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

