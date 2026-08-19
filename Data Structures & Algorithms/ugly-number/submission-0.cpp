class Solution {
public:
    bool isUgly(int n) {
        // Base case: 0 and negative numbers cannot be ugly numbers
        if (n <= 0) return false;
        
        // Keep dividing by 2 as long as it is divisible
        while (n % 2 == 0) n /= 2;
        
        // Keep dividing by 3 as long as it is divisible
        while (n % 3 == 0) n /= 3;
        
        // Keep dividing by 5 as long as it is divisible
        while (n % 5 == 0) n /= 5;
        
        // If n is reduced to 1, it only had 2, 3, and 5 as prime factors
        return n == 1;
    }
};

    