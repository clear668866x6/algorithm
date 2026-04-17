# 内容
- 前序+中序 求后序。
- 后序+中序 求前序。

- 比如前序+中序做法就是以中序为准，也就是前序找根，然后中序拆分数组。
```C++
auto dfs = [&](auto &&dfs, string a, string b) {
    if (a.empty()) return;
    char p = b.back();
    cout << char(p);
    int t = a.find(p);
    dfs(dfs, a.substr(0, t), b.substr(0, t));//访问左子树
    dfs(dfs, a.substr(t + 1), b.substr(t, b.size() - t - 1));//访问右子树
};
```

```C++
auto dfs = [&](auto &&dfs, string a, string b) {
    if (a.empty()) return;
    char p = b[0];
    int t = a.find(p);
    dfs(dfs, a.substr(0, t), b.substr(1, t));//大小必须一致
    dfs(dfs, a.substr(t + 1), b.substr(t + 1));//大小必须一样
    cout << char(p);//后序遍历，放后面
};
```


# 题单
- P1030
- P1827
- P3884