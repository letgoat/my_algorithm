#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;



// 88.合并两个有序数组
class Solution0 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp1;
        temp1.resize(m);  // 使用 resize 而不是 reserve
        for(int i = 0; i < m; i++){
            temp1[i] = nums1[i];
        }
        int count = 0;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(temp1[i] <= nums2[j]){
                nums1[count++] = temp1[i];
                i++;
            }
            else{
                nums1[count++] = nums2[j];
                j++;
            }
        }
        // 处理剩余元素
        while(i < m){
            nums1[count++] = temp1[i];
            i++;
        }
        while(j < n){
            nums1[count++] = nums2[j];
            j++;
        }
    }
};


// 27.移除元素
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        vector<int> temp;
        for(auto it: nums){
            if(it != val) {
                count++;
                temp.emplace_back(it);
            }
        }
        nums.swap(temp);
        return count;
    }
};

// 26.删除有序数组中的重复项
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        map<int, bool> flag;
        vector<int> temp;
        temp.reserve(nums.size());
        for(auto it: nums){
            if(flag[it] == false){
                k++;
                temp.emplace_back(it);
                flag[it] = true;
            }
        }
        temp.swap(nums);
        return k;
    }
};


// 80.删除有序数组中的重复项||
class Solution3 {
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size() == 1) return 1;
        int insert = 1;
        int samecount = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){ // 如果出现相同元素
                if(samecount < 2){ // 如果相同元素还未超2
                    nums[insert] = nums[i]; // 正常插入
                    insert++; // 插入下标+1
                    samecount++; // 相同count+1
                }
                // 如果相同元素超2，直接跳过不处理
            }
            else{ // 如果不是相同元素
                nums[insert] = nums[i]; // 正常插入
                insert++; // 插入下标+1
                samecount = 1; // 相同count 重置为 1
            }
        }
        nums.erase(nums.begin() + insert, nums.end()); // 将insert下标以后的元素都删除
        return nums.size();
    }
};

// 189.轮转数组
class Solution4 {
public:
    void rotate(vector<int>& nums, int k){
            if(k == 0 || nums.size() == 1 || k % nums.size() == 0){
                return ;
            }
            vector<int> temp;
            int index = k % nums.size();
            for(int i = nums.size() - index; i < nums.size(); i++){
                temp.emplace_back(nums[i]);
            }
            for(int i = 0; i < nums.size() - index; i++){
                temp.emplace_back(nums[i]);
            }
            temp.swap(nums);
    }
};


// 274.H指数
class Solution5 {
public:  
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int resultindex = 0;
        if(citations.size() == 1 && citations[0] > 0){
            return 1;
        }
        sort(citations.begin(), citations.end(), compare);
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] <= (i + 1)){
                resultindex = max(citations[i], resultindex);
            }
            else{
                resultindex = i + 1;
            }
        }
        return resultindex;
    }
private:
    static bool compare(const int& a, const int& b){
        return a > b;
    }
};

// 6.Z字形变换
class Solution6 {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int vertflag = 0;
        int flag = 1;
        vector<int> flags(s.size(), 0);
        string result;
        for(int i = 0; i < s.size(); i++){ // 先对每个字符进行行标志
            if(vertflag % 2 == 0){ // 行数增
                flags[i] = flag++;
            }
            else{ // 行数减
                flags[i] = flag--;
            }
            if(flag == 0 || flag == numRows + 1){
                vertflag++;
                if(flag == 0){
                    flag = 2;
                }
                if(flag == numRows + 1){
                    flag = numRows - 1;
                }
            }
        }
        for(int i = 1; i <= numRows; i++){
            for(int j = 0; j < s.size(); j++){
                if(flags[j] == i){
                    result += s[j];
                }
            }
        }
        return result;
    }
};