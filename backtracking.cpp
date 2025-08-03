// 回溯函数三部曲
// 1.回溯函数返回值和参数
// void backtracking(参数)

// 2.回溯函数终止条件
// if(终止条件){
// 添加结果;
// return;
// }

// 3.回溯函数遍历过程
// for(元素: 每层树的节点){
//     处理节点;
//     backtracking(路径, 选择列表); //递归
//     回溯，撤销处理结果;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 77.组合
class Solution0{
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startindex){
        if(path.size() == k){
            result.push_back(path);
            return ;
        }
        // 剪枝优化：剩余元素不足以填满组合
        for(int i = startindex; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k){
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};

// 优化版本：使用引用传递和预分配空间
class Solution1 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        path.reserve(k); // 预分配空间，避免动态扩容
        result.reserve(mycombine(n, k)); // 预分配结果空间
        
        backtracking(n, k, 1, path, result);
        return result;
    }
    
private:
    void backtracking(int n, int k, int startindex, 
                     vector<int>& path, vector<vector<int>>& result) {
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        // 剪枝优化
        for(int i = startindex; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i+1, path, result);
            path.pop_back();
        }
    }
    
    // 计算组合数的辅助函数
    int mycombine(int n, int k) {
        if (k > n - k) k = n - k;
        long long res = 1;
        for (int i = 0; i < k; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
};


// 216.组合总和|||
class Solution1{
public:
    vector<vector<int>> combinationSum3(int k, int n){
        result.clear();
        path.clear();
        backtracking(0, k, n, 1);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int sum, int k, int n, int startindex){
        if(sum > n){
            return ;
        }
        if(path.size() == k){
            if(sum == n) result.push_back(path);
            return ; //注意当path.size()时，就算sum != n，也要返回了
        }
        for(int i = startindex; i <= 9 - (k - path.size()) + 1; i++){
            path.push_back(i);
            sum += i;
            backtracking(sum, k, n, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
};


// 17.电话号码的字母组合
// 注意这题回溯树的宽度和深度，和一般概念是反的，容易出错
class Solution2{
public:
    vector<string> letterCombinations(string digits){
        result.clear();
        path.clear();
        if(digits.size() == 0) return result;
        backtracking(numbers[digits[0]], 0, digits.size(), 0, digits);
        return result;
    }
private:
    vector<string> result;
    string path;
    map<char, vector<char>> numbers = {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}}
   };
   // subject是要处理的数字对应的 "字符容器"
   // subjectid是第几个数字
   // length其实就是digits数字的个数
   // startindex是在每个字符容器的操作起始下标
   // digits就是传入的代表数字的字符串
    void backtracking(vector<char> subject, int subjectid, int length, int startindex, string digits){
        if(path.size() == length){ //如果长度够了，就操作后返回
            result.push_back(path);
            return ;
        }
        for(int i = 0; i < subject.size(); i++){ // 树的宽度是根据每个"字符容器"的大小决定的
            path.push_back(subject[i]);
            subjectid++; // 准备处理下一个字符容器，所以容器id要 +1
            backtracking(numbers[digits[subjectid]], subjectid, length, i + 1, digits); // 递归的时候，注意是处理下一个"数字容器"了
            subjectid--; // 回溯字符容器id
            path.pop_back(); // 回溯path的构造
        }
    }
};