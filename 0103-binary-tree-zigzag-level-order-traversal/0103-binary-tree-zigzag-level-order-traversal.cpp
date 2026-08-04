class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    queue<TreeNode*> q;
    q.push(root);
    int count=0;

    while(!q.empty())
    {
        int n=q.size();
        vector<int> level;

        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(count%2!=0)
        {
            reverse(level.begin(),level.end());
        }
        count++;
         ans.push_back(level);

    }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna