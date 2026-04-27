#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int val[MAXN], ls[MAXN], rs[MAXN], cnt = 0;

inline int newNode(int v) {
    int u = ++cnt;
    val[u] = v;
    ls[u] = rs[u] = 0;
    return u;
}

void f(int u) {
    if (!u) return;
    // 1
    f(ls[u]);
    // 2
    f(rs[u]);
    // 3
}

void preOrder(int u) {
    if (!u) return;
    cout << val[u] << ' ';
    preOrder(ls[u]);
    preOrder(rs[u]);
}

void inOrder(int u) {
    if (!u) return;
    inOrder(ls[u]);
    cout << val[u] << ' ';
    inOrder(rs[u]);
}

void postOrder(int u) {
    if (!u) return;
    postOrder(ls[u]);
    postOrder(rs[u]);
    cout << val[u] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int head = newNode(1);
    ls[head] = newNode(2);
    rs[head] = newNode(3);

    ls[ls[head]] = newNode(4);
    rs[ls[head]] = newNode(5);

    ls[rs[head]] = newNode(6);
    rs[rs[head]] = newNode(7);

    preOrder(head);
    cout << '\n';
    inOrder(head);
    cout << '\n';
    postOrder(head);
    cout << '\n';

    return 0;
}