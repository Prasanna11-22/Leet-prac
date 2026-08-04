class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(i==n-1) ans.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna