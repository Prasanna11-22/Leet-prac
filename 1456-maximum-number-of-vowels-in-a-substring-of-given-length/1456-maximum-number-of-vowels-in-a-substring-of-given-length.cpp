class Solution {
public:
bool isvow(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
        return true;
    }
    return false;
}
    int maxVowels(string s, int k) {
        if(s.size()==1)
        {
            return isvow(s[0]);
        }
        int count=0;
        for(int i=0;i<k;i++) 
        {
            if(isvow(s[i]))
            {
                count++;
            }
        }

        int maxi=count;

        for(int j=k;j<s.size();j++)
        {
            if(isvow(s[j-k])) 
            {
                count--;
            }
            if(isvow(s[j]))
            {
                count++;
            }

         maxi=max(maxi,count);

        }

        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna