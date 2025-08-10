#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 125.验证回文串
class Solution0 {
public:
    bool isPalindrome(string s) {
        string temp;
        // 修复：将字符串转换为小写
        for(auto it: s){
            if(isalpha(it) || isdigit(it)){
                temp += tolower(it);  // 使用 tolower() 转换单个字符
            }
        }
        if(temp.size() == 1) return true;
        if(temp.size() == 2){
            if(temp[0] == temp[1]) return true;
            else return false;
        }
        int left, right;
        if(temp.size() % 2 == 1){
            left = temp.size() / 2 - 1;
            right = temp.size() / 2 + 1;
        }
        else{
            left = temp.size() / 2 - 1;
            right = temp.size() / 2;
        }
        for(int i = 0, j = temp.size() - 1; i <= left, j >= right ; i++, j--){
            if(temp[i] != temp[j]){
                return false;
            }
        }
        return true;
    }
};


// 11.盛最多水的容器
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int i = 0, j = height.size() - 1;
        while(i < j) {
            result = height[i] < height[j] ?
                max(result, (j - i) * height[i++]):
                max(result, (j - i) * height[j--]);
        }
        return result;
    }
};