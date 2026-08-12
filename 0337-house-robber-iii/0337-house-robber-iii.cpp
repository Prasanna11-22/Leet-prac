class Solution {
public:

int lc=0,rc=1,r=2;

pair<int,int> dfs(TreeNode* root)
{
    if(!root) return {0,0};
    auto l=dfs(root->left);
    auto r=dfs(root->right);

    int take=root->val+l.second+r.second;

    int dont=max(l.first,l.second)+max(r.first,r.second);
    return {take,dont};
}
    int rob(TreeNode* root) {
        auto t=dfs(root);
        return max(t.first,t.second);
        
    }
};