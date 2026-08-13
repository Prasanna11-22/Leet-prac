class Solution {
public:
    bool checkRecord(string s) {
        int a=0,l=0;
       for(int i=0;i<s.size();i++)
       {
        char t=s[i];
        if(t=='A')
        {
            if(a<2) a++;
            else return false;
        }

        if(t=='L')
        {
            if((i!=0)&&(s[i+1]=='L')&&(s[i-1]=='L'))
            {
               return false;
            }
        }
       } 
       return (a<2&&l<=3);
    }
};