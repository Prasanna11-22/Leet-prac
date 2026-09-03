class Solution {
public:
    int trap(vector<int>& h) {
        int lmax=0,rmax=0;
        int tot=0;
        
        int l=0,r=h.size()-1;

        while(l<r)
        {
            lmax=max(lmax,h[l]);
            rmax=max(rmax,h[r]);

            if(h[l]<=h[r])
            {
                tot+=lmax-h[l];
                l++;
            }
            else if(h[r]<h[l])
            {
                tot+=rmax-h[r];
                r--;
            }
        }
        return tot;
    }
};