## 两种写代码的方式：记忆化搜索与递推
### 记忆化搜索

```c++
int dp[状态表示];
int dfs(状态表示) {
    if (决策边界) return 决策边界答案; // 决策边界
    if (dp[状态表示] != 无效数值) return dp[状态表示]; // 记忆化
    for (当前状态表示的 子状态) dfs(子状态) 更新 dp[状态表示]; // 状态转移
    return dp[状态表示];
}
int solve() {
    memset(dp, 无效数值, sizeof(dp));
    return dfs(原问题状态);
}
```

### 递推： 设置边界