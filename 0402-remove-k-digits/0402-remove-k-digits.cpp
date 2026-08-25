class Solution {
public:
    string removeKdigits(string num, int k) {
       string st="";

        if(k==num.size()) return "0";

       for(int i=0;i<num.length();i++)
       {
        while(!st.empty()&& k>0 &&st.back()>(num[i]))
        {
            st.pop_back();
            k--;
        }
        st.push_back(num[i]);
       } 


        while(k>0 &&!st.empty())
        {
            st.pop_back();
            k--;
        }
        
      auto pos =st.find_first_not_of('0');
      if(pos==string::npos) return "0";
      else
      {
        st.erase(0,pos);
      }
       return st;
    }
};