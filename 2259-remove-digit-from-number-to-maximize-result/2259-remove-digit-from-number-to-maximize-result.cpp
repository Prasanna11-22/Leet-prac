class Solution {
public:
    string removeDigit(string num, char digit) {
        string maxi="";

        for(int i=0;i<num.size();i++)
        {
            if(num[i]==digit) 
            {
                string str1=num.substr(0,i)+num.substr(i+1,num.size());
                maxi=max(str1,maxi);
            }
        }
        return maxi;
    }
};