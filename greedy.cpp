#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;




// 435. 无重叠区间

class Solution0 {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            if(intervals.size() == 0) return 0;
            sort(intervals.begin(), intervals.end(), cmp);
            int count = 0;
            int end = intervals[0][1];
            for(int i = 1; i < intervals.size(); i++){
                if(intervals[i][0] >= end){ // 无重叠的情况
                    end = intervals[i][1];
                }
                else{ // 有重叠的情况
                    end = min(end, intervals[i][1]);
                    count++;
                }
            }
            return count;
    }
};


// 763.划分字母区间
class Solution1 {
public:
    vector<int> partitionLabels(string s){
        vector<int> result;
        map<char, int> charmaxdistance;
        // 首先记录每个字符最后出现的位置
        for(int i = 0; i < s.size(); i++){
            charmaxdistance[s[i]] = max(charmaxdistance[s[i]], i);
        }
        int current_max = 0; //当前字符段的某个字符的最远距离（最后出现下标）
        int count = 0; //每一段字符区间长度
        for(int i = 0; i < s.size(); i++){
            current_max = max(charmaxdistance[s[i]], current_max);
            count++;
            if(i == charmaxdistance[s[i]] && current_max == i){ //说明分割完成
                result.push_back(count);
                count = 0; //重新进行分割，所以计数重置
                current_max = 0; //重新进行分割，当前子串的字符最远距离归零
            }
        }
        return result;
    }
};


// 56.合并区间
class Solution2 {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        result.reserve(intervals.size()); // 预分配空间，避免动态扩容
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > right){ //如果不重叠
                result.emplace_back(initializer_list<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else{ //如果重叠
                right = max(right, intervals[i][1]);
            }
        }
        //将最后一个区间进行输出
        result.emplace_back(initializer_list<int>{left, right});
        return result;
    }
};

