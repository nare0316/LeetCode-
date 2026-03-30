#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
    public:
        std::pair<char, char> half_adder(int a, int b) {
            return {(a^b) + '0', (a & b) + '0'};
        }
    
        std::pair<char, char> full_adder(int a, int b, int c) {
            auto [s1, c1] = half_adder(a, b);
            auto [s2, c2] = half_adder(s1 - '0', c);
            return {s2, ((c1 - '0') | (c2 - '0')) + '0'};
        }
    
        string addBinary(string a, string b) {
            size_t len_a = a.length();
            size_t len_b = b.length();
            size_t loop_count = std::max(len_a, len_b);
    
            std::string res = "";
    
            int8_t x = 0;
            int8_t y = 0;
            int8_t carry_prev = 0;
        
            for (size_t i {0}; i < loop_count; ++i) {
                if (i >= len_a) {
                    x = 0;
                } else {
                    x = a[len_a - i - 1] - '0';
                }
    
                if (i >= len_b) {
                    y = 0;
                } else {
                    y =  b[len_b - i - 1] - '0';
                }
    
                auto [sum, carry] = full_adder(x, y, carry_prev);
                carry_prev = carry - '0';
                
                res += sum;
            }
    
            if (carry_prev == 1) {
                res += '1';
            }
    
            std::reverse(res.begin(), res.end());
            return res;
        }
    };