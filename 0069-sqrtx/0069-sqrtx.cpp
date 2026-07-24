class Solution {
public:
    int mySqrt(int x) {
      if(x<2) return x;
      int l=0,r=x/2,res=1,i=1;
      while(l<=r)
      {
        long long mid=l+(r-l)/2;
       //cout<<i++<<" "<<l<<" "<<r<<" "<<mid<<"->"<<mid*mid<<endl;
        if((mid*mid)<=x)
        {
            res=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
      }
    
    return r;
        
    }
};