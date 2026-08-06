class Solution {
public:
int prod(int n)
{
    int pd=1;
    while(n>0)
    {
        
        pd*=n%10;
        n/=10;
    }

    return pd;
}
    int smallestNumber(int n, int t) {
       for(int i=n;i<=n+10;i++)
       {
       
        int mul=prod(i);
        if((mul%t)==0)
        return i; 

       }
    return n+10;

    }
};