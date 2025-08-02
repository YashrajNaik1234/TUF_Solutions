class Solution {
public:
    int countSetBits(int n) {
        // Your code goes here
        int count = 0;
        while (n > 0) {
            if (n & 1) count++;
            n >>= 1;
        }
        return count;
    }
};
