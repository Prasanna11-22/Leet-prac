class Solution {
public:
    bool checkDivisibility(int n) {
        int k=n,sum=0,prod=1;
        while(k>0)
        {
            int t=k%10;
            sum+=t;
            prod*=t;
            k/=10;
        }

        int totsum=sum+prod;

        if(totsum==0) return false;
        return (n%totsum==0);
    }
};