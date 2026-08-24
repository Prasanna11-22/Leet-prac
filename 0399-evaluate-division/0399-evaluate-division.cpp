class Solution {
public:

double dfs(string from,string to ,unordered_map<string,vector<pair<string,double>>> &adj,unordered_set<string> &vis,double res)
{
    if(from==to) return res;
    if(vis.find(from)==vis.end())  vis.insert(from);
    else return -1;

    for(auto k : adj[from])
    {      
      double ans=dfs(k.first,to,adj,vis,res*(k.second));
      if(ans==-1) continue; 
      else return ans;
    }
    return -1;
}
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& queries) {

       unordered_map<string,vector<pair<string,double>>> adj;
       vector<double> sol;

       for(int i=0;i<eq.size();i++)
       {
        adj[eq[i][0]].push_back({eq[i][1],val[i]});
        adj[eq[i][1]].push_back({eq[i][0],(double)1.0/val[i]});
       }
    
    for(auto k : queries)
    {
        string from=k[0];
        string to=k[1];
        if(adj.find(from)!=adj.end()&&from==to)
        {
            sol.push_back(1.0);
        }
        else if(adj.find(from)==adj.end()||adj.find(to)==adj.end()) 
        {
            sol.push_back(-1.0);
        }
        else
        {
        double res=1;
        unordered_set<string> vis;
        double ans=dfs(from,to,adj,vis,res);
        sol.push_back(ans);
        }
    }
        return sol;
        
    }
};
  