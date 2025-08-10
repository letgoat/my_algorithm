#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;




// 3.无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int result = 0;
        int left = 0;
        unordered_set<char> lookup;
        for(int i = 0; i < s.size(); i++){
            while(lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left++;
            }
            result = max(result, i - left + 1);
            lookup.insert(s[i]);
        }
        return result;
    }
};