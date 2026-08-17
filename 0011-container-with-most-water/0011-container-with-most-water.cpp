class Solution {
public:
    int maxArea(vector<int>& h) {
        if(h.size()==2) return min(h[0],h[1]);
        int i=0,j=h.size()-1;
        int maxi=0;

        while(i<j)
        {
            int mini=min(h[i],h[j]);
            maxi=max((j-i)*(min(h[i],h[j])),maxi);
            cout<<h[i]<<" "<<h[j]<<" "<<maxi<<endl;
            if(mini==h[i])
            {
                i++;
            }
            else
            {
                j--;
            }

        }
        return maxi;
    }
};