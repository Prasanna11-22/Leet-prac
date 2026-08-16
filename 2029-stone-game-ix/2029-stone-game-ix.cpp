class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c1=0,c2=0,c0=0;
        for(int s : stones)
        {
            if(s%3==0)
            {
                c0++;
            }
            else if(s%3==1)
            {
                c1++;
            }
            else if(s%3==2)
            {
                c2++;
            }
        }

        if(c0%2==0)
        {
            return (c1>0)&&(c2>0);
        }

        return abs(c1-c2)>2;
    }
};