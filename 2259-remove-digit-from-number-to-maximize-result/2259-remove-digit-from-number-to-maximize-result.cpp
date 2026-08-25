class Solution {
public:
    string removeDigit(string num, char digit) {
        string res="";
        string maxi="";

        for(int i=0;i<num.size();i++)
        {
            if(num[i]==digit) 
            {
                string str1=num.substr(0,i);
                string str2=num.substr(i+1,num.size());
                str1=str1+str2;
                maxi=max((str1),maxi);
            }
        }
        return maxi;
    }
};