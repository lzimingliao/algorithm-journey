#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int val[MAXN], ls[MAXN], rs[MAXN], cnt;
int stk[MAXN], top;
int collect[MAXN], c_top;

inline int newNode(int v) {
    int u = ++cnt;
    val[u] = v;
    ls[u] = rs[u] = 0;
    return u;
}

// Pre-order traversal, iterative
void preOrder(int head) {
    if (!head) return;
    top = 0;
    stk[top++] = head;
    while (top > 0) {
        int u = stk[--top];
        cout << val[u] << " ";
        if (rs[u]) stk[top++] = rs[u];
        if (ls[u]) stk[top++] = ls[u];
    }
    cout << "\n";
}

// In-order traversal, iterative
void inOrder(int head) {
    if (!head) return;
    top = 0;
    int u = head;
    while (top > 0 || u) {
        if (u) {
            stk[top++] = u;
            u = ls[u];
        } else {
            u = stk[--top];
            cout << val[u] << " ";
            u = rs[u];
        }
    }
    cout << "\n";
}

// Post-order traversal, iterative - 2 stacks
void postOrderTwoStacks(int head) {
    if (!head) return;
    top = 0;
    c_top = 0;
    stk[top++] = head;
    while (top > 0) {
        int u = stk[--top];
        collect[c_top++] = u;
        if (ls[u]) stk[top++] = ls[u];
        if (rs[u]) stk[top++] = rs[u];
    }
    while (c_top > 0) cout << val[collect[--c_top]] << " ";
    cout << "\n";
}

// Post-order traversal, iterative - 1 stack
void postOrderOneStack(int head) {
    if (!head) return;
    top = 0;
    stk[top++] = head;
    while (top > 0) {
        int cur = stk[top - 1];
        if (ls[cur] && ls[cur] != head && rs[cur] != head) {
            stk[top++] = ls[cur];
        } else if (rs[cur] && rs[cur] != head) {
            stk[top++] = rs[cur];
        } else {
            cout << val[cur] << " ";
            head = stk[--top];
        }
    }
    cout << "\n";
}

int main() {
    int head = newNode(1);
    ls[head] = newNode(2);
    rs[head] = newNode(3);

    ls[ls[head]] = newNode(4);
    rs[ls[head]] = newNode(5);

    ls[rs[head]] = newNode(6);
    rs[rs[head]] = newNode(7);

    preOrder(head);
    inOrder(head);
    postOrderTwoStacks(head);
    postOrderOneStack(head);

    return 0;
}
