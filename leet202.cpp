class Solution {
    public:
        int get_res(int n) {
            int res = 0;
            int digit = 0;
            while (n) {
                digit = n % 10;
                res = res + digit * digit;
                n /= 10;
            }
            return res;
        }
    
        bool isHappy(int n) {
            int fast = n;
            int slow = n;
            while (true) {
                slow = get_res(slow);
                if (slow == 1) {
                    return true;
                }
                fast = get_res(get_res(fast));
                if (slow == fast) {
                    return false;
                }
            }
        }
    };