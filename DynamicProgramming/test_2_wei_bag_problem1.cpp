#include <iostream>
#include <vector>
using namespace std;

// 二维数组背包问题
void test_2_wei_bag_problem1() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagweight = 4;

  vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
  for (int j = weight[0]; j <= bagweight; j++) {
    dp[0][j] = value[0];
  }
  for (int i = 1; i < weight.size(); i++) {  // 遍历物品
    for (int j = 0; j <= bagweight; j++) {   // 遍历背包
      if (j < weight[i])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
    }
  }
  cout << dp[weight.size() - 1][bagweight] << '\n';
}

// 一维数组背包问题
void test_1_wei_bag_problem1() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int bagweight = 4;

  // 初始化
  vector<int> dp(bagweight + 1, 0);
  for (int i = 0; i < weight.size(); i++) {         // 遍历物品
    for (int j = bagweight; j >= weight[i]; j--) {  // 遍历背包
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  cout << dp[bagweight] << '\n';
}

int main() {
  test_1_wei_bag_problem1();
  cout << "test";
  return 0;
}