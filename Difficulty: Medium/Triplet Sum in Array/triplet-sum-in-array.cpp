class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
       sort(arr.begin(),arr.end());
       int tsum=arr[0]+arr[1]+arr[2];
       
       for(int i=0;i<arr.size()-2;i++)
       {
           int l=i+1,h=arr.size()-1;
           
           while(l<h)
           {
               int sum=arr[i]+arr[l]+arr[h];
               if(sum==target)
               {
                   return true;
               }
               
               if(sum<=target)
               {
                   l++;
               }
               else
               {
                   h--;
               }
           }
       }
       return false;
    }
};