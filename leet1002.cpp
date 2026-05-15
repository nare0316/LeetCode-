class Solution {
    public:
        vector<string> commonChars(vector<string>& words) {
            size_t size = words.size();
            std::set<char> st;
            st.insert(words[0].begin(), words[0].end());
            std::vector<int> commons(26, 0);
            
            for (const auto chr : words[0]) {
                ++commons[chr - 'a'];
            }
            for (size_t i{1}; i < size; ++i) {
                std::vector<int> tmp(26, 0);
                for (const auto chr : words[i]) {
                    if (st.contains(chr)) {
                        ++tmp[chr - 'a'];
                    }
                }
                for (const auto chr : words[0]) {
                    commons[chr - 'a'] = std::min(tmp[chr - 'a'], commons[chr - 'a']);
                }
            }
            std::vector<std::string> res; 
            for (size_t i{}; i < 26; ++i) {
                if (commons[i] != 0) {
                    while (commons[i]) {
                        std::string sym(1, 'a' + i);
                        res.push_back(sym);
                        --commons[i];
                    }
                }
            }
            return res;
        }
};