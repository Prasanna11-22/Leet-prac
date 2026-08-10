class Solution {
public:
vector<int> res;
void preord(TreeNode* root,int maxval)
{
    if(!root) return;

    if(root->val>=maxval)
    {
        res.push_back(root->val);
       // cout<<maxval<<" "<<root->val<<endl;
        maxval=root->val; 
    }
    preord(root->left,maxval);
    preord(root->right,maxval);


}
    int goodNodes(TreeNode* root) {
        preord(root,-1e5);

        return res.size();
    }
};