
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to avoid overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long ans = 0;

        // Subtract the largest possible multiples using bit shifting
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        // Apply sign
        if (negative) {
            ans = -ans;
        }

        return (int)ans;
    }
};
