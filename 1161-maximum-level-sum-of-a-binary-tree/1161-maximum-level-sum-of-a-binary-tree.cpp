class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int count=1;
        if(root==nullptr) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN,maxc=-1;
        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                sum+=(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(sum>maxi)
            {
                maxi=sum;
                maxc=count;
            }
            count++;
        }
        return maxc;
    }
};