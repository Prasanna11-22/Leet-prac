class Solution {
public:
    string removeKdigits(string num, int k) {
       string ans="";

        if(k==num.size()) return "0";

       stack<int> st;
       for(int i=0;i<num.length();i++)
       {
        while(!st.empty()&& k>0 &&st.top()>(num[i]-'0'))
        {
            st.pop();
            k--;
        }
        st.push(num[i]-'0');
       } 


        while(k>0 &&!st.empty())
        {
            st.pop();
            k--;
        }
        
        cout<<k<<endl;

       while(!st.empty())
       {
            ans+=to_string(st.top());
            st.pop();
       }
       reverse(ans.begin(),ans.end());

      auto pos =ans.find_first_not_of('0');
      if(pos==string::npos) return "0";
      else
      {
        ans.erase(0,pos);
      }
       return ans;
    }
};