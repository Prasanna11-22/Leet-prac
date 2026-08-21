class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        
        // k represents the current position: 1 (ones), 10 (tens), 100 (hundreds), etc.
        for (long long k = 1; k <= n; k *= 10) {
            long long r = n / k; 
            long long m = n % k; 

            cout<<k<<" "<<r<<" "<<m<<" ";
            
            // Calculate full blocks of 10 that pass through this position
            count += (r + 8) / 10 * k;
            cout<<count<<" ";
            
            // If the current digit is exactly 1, add the remainder (suffix) + 1
            if (r % 10 == 1) {
                count += m + 1;
               
            }
            cout<<count<<endl;
        }
        
        return count;
    }
};