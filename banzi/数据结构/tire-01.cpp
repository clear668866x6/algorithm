// CF 665E
struct Tire {
    static constexpr int N = 2e6 + 10;
    struct E {
        int ch[2];
        int siz;
    } tr[N * 30];
    int idx;

    Tire() {
        idx = 2;
    }

    void insert(int x) {
        int u = 1;
        FORD(i, 0, 32) {
            int v = x >> i & 1;
            if (!tr[u].ch[v]) tr[u].ch[v] = idx++;
            u = tr[u].ch[v];
            tr[u].siz++;
        }
    }

    int query(int x, int k) {
        int u = 1;
        int tot = 0;
        FORD(i, 0, 32) {
            int a = x >> i & 1, b = k >> i & 1;
            if (!b) {
                tot += tr[tr[u].ch[a ^ 1]].siz;
            }
            u = tr[u].ch[a ^ b];
        }
        tot += tr[u].siz;
        return tot;
    }

} A;

// 版本2

struct Tire {
    static constexpr int N = 3100000;
    vector<int32_t> tr[2];
    vector<int32_t> cnt;
    int32_t idx;

    Tire() {
        idx = 1;
        tr[0].resize(N, 0);
        tr[1].resize(N, 0);
        cnt.resize(N, 0);
    }

    inline void insert(int x) {
        int32_t p = 0;
        FORD(i, 0, 29) {
            int u = x >> i & 1;
            cnt[p]++;
            if (!tr[u][p]) tr[u][p] = idx++;
            p = tr[u][p];
        }
        cnt[p]++;
    }

    inline void remove(int x) {
        int32_t p = 0;
        FORD(i, 0, 29) {
            int u = x >> i & 1;
            cnt[p]--;
            p = tr[u][p];
        }
        cnt[p]--;
    }

    inline int findmx(int x) {
        int32_t p = 0;
        int ans = 0;
        FORD(i, 0, 29) {
            ans *= 2;
            int u = x >> i & 1;
            if (tr[u ^ 1][p] && cnt[tr[u ^ 1][p]]) {
                p = tr[u ^ 1][p];
                ans++;
            } else {
                p = tr[u][p];
            }
        }
        return ans;
    }

    inline int findmn(int x) {
        int32_t p = 0;
        int ans = 0;
        FORD(i, 0, 29) {
            ans *= 2;
            int u = x >> i & 1;
            if (tr[u][p] && cnt[tr[u][p]]) {
                p = tr[u][p];
            } else {
                p = tr[u ^ 1][p];
                ans++;
            }
        }
        return ans;
    }
};