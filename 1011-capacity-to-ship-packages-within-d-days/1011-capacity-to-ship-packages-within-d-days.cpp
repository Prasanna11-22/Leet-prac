class Solution {
public:


bool isposs(vector<int>& weights,int w,int days)
{
    int sum=0;
    int dayused=1;

    for(int i : weights)
    {
        if(i+sum<=w) sum+=i;
        else
        {
            sum=i;
            dayused++;
        }
    }
    return dayused<=days;

}
    int shipWithinDays(vector<int>& weights, int days) {

       
       int l=*max_element(weights.begin(),weights.end());
       int r=accumulate(weights.begin(),weights.end(),0);
       int ans=0;

    //    for(int i=l;i<=r;i++) cout<<i<<"->"<<isposs(weights,i,days)<<endl;
    //    cout<<endl;

       while(l<=r)
       {
        int mid=l+(r-l)/2;
        bool t=isposs(weights,mid,days);
       // cout<<mid<<"->"<<t<<endl;
        if(t)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
       } 
       return ans;
    }
};