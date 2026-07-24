class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0,r=arr.size()-1;

        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(arr[mid]<=arr[r])
            {
                r=mid;
            }
            else if(arr[l]<=arr[mid])
            {
                l=mid+1;
            }
            else
            {
                return arr[l];
            }
        }
        return arr[l];
    }
};