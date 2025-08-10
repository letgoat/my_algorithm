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

// 26. 删除有序数组中的重复项
<<<<<<< Updated upstream






// 80. 删除有序数组中的重复项 ||
class Solution3 {
public:
    int removeDuplicates(vector<int>&  nums){
        

        return nums.size();
    }

}
=======
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


// 80. 删除有序数组中的重复项||
class Solution {
public:
    int removeDuplicates(vector<int>& nums){

    }
};
>>>>>>> Stashed changes
