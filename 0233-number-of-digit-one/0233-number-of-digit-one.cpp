class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        
        for (long long k = 1; k <= n; k *= 10) {
            
            long long left = n / (k * 10);  // The numbers to the left (full cycles)
            long long digit = (n / k) % 10; // The specific digit we are checking
            long long right = n % k;        // The numbers to the right (the saved tail)
            
            if (digit == 0) {
                // We haven't reached the 1s for this cycle yet.
                // Just take the full batches completed.
                count += left * k;
                
            } else if (digit == 1) {
                // We are stuck halfway through the 1s.
                // Take the full batches + the numbers we rolled past (right + 1).
                count += (left * k) + (right + 1);
                
            } else {
                // The digit is 2 through 9. We completely passed the 1s.
                // Take the full batches + 1 extra batch.
                count += (left + 1) * k;
            }
        }
        
        return count;
    }
};