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
vector<vector<int>> res;


bool isleaf(TreeNode* node)
{
    return ((node)&&(!node->left)&&(!node->right));
}

void rec(TreeNode* root,int& tsum,int sum,vector<int>&ans)
{
    if(!root) return;
    //if(sum>tsum) return;
    sum+=root->val;
   //cout<<sum<<endl;

    ans.push_back(root->val);

    if(isleaf(root)&&(tsum==sum))
    {
        res.push_back(ans);
    }

    rec(root->left,tsum,sum,ans);
    rec(root->right,tsum,sum,ans);

    ans.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> ans;
        rec(root,targetSum,0,ans);
        return res;

        
    }
};