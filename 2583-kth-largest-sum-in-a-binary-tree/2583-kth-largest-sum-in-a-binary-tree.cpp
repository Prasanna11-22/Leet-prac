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
priority_queue<long long> maxi;
void levord(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int n=q.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
        TreeNode* t=q.front();
        q.pop();
        sum+=t->val;
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);

        }
        maxi.push(sum);
    }
}

    long long kthLargestLevelSum(TreeNode* root, int k) {
        levord(root);

        if(k>maxi.size()) return -1;

        for(int i=0;i<k-1;i++)
        {
            maxi.pop();
        }

        return maxi.top();
    }
};