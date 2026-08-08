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
bool chkinc(vector<int> &res)
{
    for(int i=0;i<res.size()-1;i++)
    {
        if(res[i]>=res[i+1])
        {
            return false;
        }
        if(res[i]%2==0)
        {
            return false;
        }
    }

        if(res[res.size()-1]%2==0)
        {
            return false;
        }

    return true;
}

bool chkdec(vector<int> &res)
{
    for(int i=0;i<res.size()-1;i++)
    {
        if(res[i]<=res[i+1])
        {
            return false;
        }
        if(res[i]%2!=0)
        {
            return false;
        }
    }

     if(res[res.size()-1]%2!=0)
        {
            return false;
        }

    return true;
}

    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;

        while(!q.empty())
        {
            vector<int> res;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
            TreeNode* t=q.front();
            q.pop();

            res.push_back(t->val);

            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            }
           
            if(count%2==0)
            {
                if(!chkinc(res))
                {
                    return false;
                }
            }
            else
            {
                if(!chkdec(res))
                {
                    return false;
                }
            }
            count++;
        }

        return true;
    }
};