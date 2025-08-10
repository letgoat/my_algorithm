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

// 二维vector正确初始化示例
class VectorInitExamples {
public:
    void correctInitialization() {
        int m = 3, n = 4;
        
        // 方法1：推荐方式 - 一行完成
        vector<vector<int>> dp1(m, vector<int>(n, 0));
        cout << "方法1 - dp1大小: " << dp1.size() << "x" << dp1[0].size() << endl;
        
        // 方法2：分步初始化
        vector<vector<int>> dp2(m);
        for (int i = 0; i < m; i++) {
            dp2[i] = vector<int>(n, 0);
        }
        cout << "方法2 - dp2大小: " << dp2.size() << "x" << dp2[0].size() << endl;
        
        // 方法3：使用resize
        vector<vector<int>> dp3;
        dp3.resize(m, vector<int>(n, 0));
        cout << "方法3 - dp3大小: " << dp3.size() << "x" << dp3[0].size() << endl;
        
        // 方法4：使用花括号初始化（C++11）
        vector<vector<int>> dp4 = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        cout << "方法4 - dp4大小: " << dp4.size() << "x" << dp4[0].size() << endl;
        
        // 验证初始化结果
        cout << "dp1[0][0] = " << dp1[0][0] << endl;
        cout << "dp2[1][1] = " << dp2[1][1] << endl;
        cout << "dp3[2][2] = " << dp3[2][2] << endl;
    }
    
    // 常见错误示例
    void commonMistakes() {
        cout << "\n=== 常见错误示例 ===" << endl;
        
        int m = 2, n = 3;
        
        // ❌ 错误1：语法错误
        // vector<vector<int>(n, 0)> dp(m, 0);  // 编译错误
        
        // ❌ 错误2：维度不匹配
        vector<vector<int>> dp1(m, vector<int>(n, 0));
        // dp1[0] = vector<int>(n+1, 0);  // 运行时错误：维度不匹配
        
        // ❌ 错误3：访问未初始化的元素
        vector<vector<int>> dp2(m);
        // cout << dp2[0][0];  // 运行时错误：未初始化
        
        // ❌ 错误4：越界访问
        // dp1[m][n] = 1;  // 运行时错误：越界访问
        // dp1[0][n] = 1;  // 运行时错误：越界访问
        
        cout << "常见错误已注释，避免运行时崩溃" << endl;
    }
    
    // 动态规划中的正确使用
    void dpExample() {
        cout << "\n=== 动态规划示例 ===" << endl;
        
        int m = 5, n = 5;
        
        // 正确的DP数组初始化
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // 初始化第一行和第一列
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;  // 第一列
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;  // 第一行
        }
        
        // 填充DP数组
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        cout << "DP数组右下角值: " << dp[m-1][n-1] << endl;
        cout << "DP数组大小: " << dp.size() << "x" << dp[0].size() << endl;
    }
};