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
string s="";
int sum=0;

bool isleaf(TreeNode* node)
{
    return (node)&&(!node->left)&&(!node->right);
}

void rec(TreeNode* root,string s) {
         if(root==nullptr) return;

         string t= s+to_string(root->val);
         cout<<t<<endl;
         if(isleaf(root))
          {
             sum+=stoi(t);
             return;
          }
           
          if(!isleaf(root))
          {
            rec(root->left,t);
            rec(root->right,t);
            
          }
}

    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        // string s="";
        //  s+=to_string(root->val);
        rec(root,s);
       return sum;
    }
};