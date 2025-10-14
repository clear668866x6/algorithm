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