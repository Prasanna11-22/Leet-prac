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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {


        if(depth==1)
        {
            TreeNode* t1=new TreeNode(val);
            t1->left=root;
            return t1;
        }

        queue<TreeNode*> q;
        q.push(root);
        int dep=0;
         
         TreeNode* temp2=nullptr;
        while(!q.empty())
        {
            dep++;
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                
                if(dep!=depth-1)
                {
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
                else
                {
                TreeNode* temp1=new TreeNode(val);
                temp1->left=t->left;
                t->left=temp1;

            
                TreeNode* temp2=new TreeNode(val);
                temp2->right=t->right;
                t->right=temp2;
                }
            }
        }
        return root;
    }
};