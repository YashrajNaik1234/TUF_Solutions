class Solution {
public:
    bool checkIthBit(int n, int i) {
        // Your code goes here
        return (1 << i) & n;
    }
};
