class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n=q.size();
            double sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                sum+=temp->val;
            }
            double avg=sum/n;
            res.push_back(avg);
        }

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna