class Solution {
public:
int v,c;
vector<int> dx={1,-1,0,0};
vector<int> dy={0,0,-1,1};

bool isposs(int lim,vector<vector<int>>&h)
{
   // if(h[0][0]>lim) return false;
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(v,vector<bool>(c,false));
    q.push({0,0});
    vis[0][0]=true;

    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        if(x==v-1&&y==c-1) return true;

        for(int i=0;i<4;i++)
        {
            int nr=x+dx[i];
            int nc=y+dy[i];

            if(nr<0||nc<0||nr>=v||nc>=c) continue;

            if((abs(h[nr][nc]-h[x][y])<=lim)&&(!vis[nr][nc]))
            {
                vis[nr][nc]=true;
                q.push({nr,nc});
            }
        }
    }

    return false;
}
    int minimumEffortPath(vector<vector<int>>& h) {
        
        v=h.size(),c=h[0].size();
        int mx = INT_MIN, mn = INT_MAX;


     for (auto &row : h) 
     {
       mx=max(mx,*max_element(row.begin(),row.end()));
       mn=min(mn,*min_element(row.begin(),row.end()));
    }

        int l=0,r=mx-mn,ans=r;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isposs(mid,h))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return ans;
    }
};