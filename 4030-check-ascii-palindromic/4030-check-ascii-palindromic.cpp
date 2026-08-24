class Solution {
public:
    bool isPalindromic(string s) {
        string t="";
        for( char i : s)
        {
            bitset<8>b(i);
            t+=b.to_string();
        }

        string chk=t;
        reverse(chk.begin(),chk.end());
        return (t==chk);
    }
};