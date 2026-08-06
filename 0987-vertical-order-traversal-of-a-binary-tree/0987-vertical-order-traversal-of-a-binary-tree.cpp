class Solution {
public:
  map<int,map<int,multiset<int>>> nodes;
void preord(TreeNode* root,int vert,int lev)
{
    if(!root) return;

    nodes[vert][lev].insert(root->val);
    preord(root->left,vert-1,lev+1);
    preord(root->right,vert+1,lev+1);
}

    vector<vector<int>> verticalTraversal(TreeNode* root) {
      
        preord(root,0,0);

        vector<vector<int>> res;

        for(auto axi : nodes)
        {
            vector<int> temp;
            for(auto le : axi.second)
            {
                temp.insert(temp.end(),le.second.begin(),le.second.end());
            }
            res.push_back(temp);
        }

    return res;
    }
};