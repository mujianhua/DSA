/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    QuickSort(nums, 0, n - 1, n);
    return nums;
  }

  // 插入排序
  void InsertSort(vector<int>& nums, int n) {
    for (int i = 0; i < n; i++) {
      int temp = nums[i];
      int j = i - 1;
      while (j >= 0 && nums[j] > temp) {
        nums[j + 1] = nums[j];
        j--;
      }
      nums[j + 1] = temp;
    }
  }

  // 快速排序 超时???
  void QuickSort(vector<int>& nums, int low, int high, int n) {
    if (low < high) {
      int pivotpos = partition(nums, low, high);
      QuickSort(nums, low, pivotpos - 1, n);
      QuickSort(nums, pivotpos + 1, high, n);
    }
  }
  int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[low];  // ref 以此ref为分界线
    while (low < high) {
      while (low < high && nums[high] >= pivot) --high;
      nums[low] = nums[high];
      while (low < high && nums[low] <= pivot) ++low;
      nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> testdata{2, 1, 4, 3, 5};
  vector<int> result = s.sortArray(testdata);
  cout << "test";
  return 0;
}
