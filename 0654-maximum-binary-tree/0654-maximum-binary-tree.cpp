class Solution {
public:

TreeNode* build(vector<int>& nums,int l,int r)
{
    if(l>r) return nullptr;
    int mid=l;
    for(int i=l;i<=r;i++)
    {
        if(nums[i]>nums[mid])
        {
            mid=i;
        }
    }

    TreeNode* root=new TreeNode(nums[mid]);

    root->left=build(nums,l,mid-1);
    root->right=build(nums,mid+1,r);

    return root;
}

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
       return build(nums,0,n-1);
        
    }
};