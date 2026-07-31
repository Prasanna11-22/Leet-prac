class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int sum=0,k=0;
        for(int i=0;i<cost.size();i++)
        {
            if(k==2)
            {
                k=0;
                continue;
            }
            else
            {
                k++;
                sum+=cost[i];
            }
        }

        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna