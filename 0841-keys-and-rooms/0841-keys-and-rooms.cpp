class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n+1,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(int nei : rooms[node])
            {
                if(!vis[nei])
                {
                    vis[nei]=true;
                    q.push(nei);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i]) return false;
        }
        return true;

        
    }
};