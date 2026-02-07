#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct node {
    int v;
    node *next;
} a[100010], *head;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    a[1].v = 1;
    head = &a[1];
    a[1].next = NULL;
    map<int, int> mp;
    mp[1] = 1;
    for (int i = 2; i <= q + 1; i++) {
        int f;
        node *p = head;
        cin >> f;
        if (f == 1) {
            int x = 0, y = 0;
            cin >> x >> y;
            a[i].v = y;
            int idx = mp[x];
            // for (node *p = head; p; p = p->next) {
            //     if (p->v == x) {
            //         node *t = p->next;
            //         p->next = &a[i];
            //         a[i].next = t;
            //         break;
            //     }
            // }
            node *t = a[idx].next;
            a[idx].next = &a[i];
            a[i].next = t;
            mp[y] = i;
        }

        if (f == 2) {
            int x;
            cin >> x;
            node *p = a[mp[x]].next;
            if (p == NULL) {
                cout << 0 << endl;
            } else {
                cout << p->v << endl;
            }
            // for (node *p = head; p; p = p->next) {
            //     if (p->v == x) {
            //         if (p->next == NULL) {
            //             cout << "0" << endl;
            //         } else {
            //             cout << p->next->v << endl;
            //         }
            //         break;
            //     }
            // }
        }

        if (f == 3) {
            int x;
            cin >> x;
            if (a[mp[x]].next != NULL) {
                a[mp[x]].next = a[mp[x]].next->next;
            }
            // for (node *p = head; p; p = p->next) {
            //     if (p->v == x) {
            //         if (p->next == NULL)
            //             break;
            //         else {
            //             p->next = p->next->next;
            //             break;
            //         }
            //     }
            // }
        }
    }
}